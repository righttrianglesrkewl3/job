import scrapy
import collections
import os
# MUST be scrapy.linkextractors with an 's' import LinkExtractor (singular)
from scrapy.linkextractors import LinkExtractor
from scrapy.spiders import Rule, CrawlSpider
from scrapy.http import FormRequest
from scrapy.http import Request
from air_mongo_project.items import AirMongoProjectItem
from air_mongo_project.items import AirMongoArrivalItem
from scrapy_splash import SplashRequest

# usage
#scrapy crawl <spider name> -o file.csv -t csv

class FlyMongoSpiderSpider(scrapy.Spider):
    name = 'arrivals_fly_mongo_spi'
    start_urls = ['https://www.flightradar24.com/']
    custom_settings = {"FEEDS": {"output_files/arrival_results_10_14_20.csv": {"format": "csv"}},'CONCURRENT_REQUESTS': 5}

    def parse(self, response):
        # give login creds here
        login_data = {'username': 'kevinz1991@gmail.com',
                        'password': 'Canseco1345'
                        }

        yield FormRequest(url=self.start_urls[0], formdata=login_data, callback=self.after_login_nav_to_airports) # headers = self.headers

    def after_login_nav_to_airports(self, response):
        # confirm login with terminal message
        print('*'*80, '\n','[INFO] Logged in!')

        # next page / do stuff
        airports_url = ['https://www.flightradar24.com/data/airports/united-states']

        yield SplashRequest(url=airports_url[0], callback=self.scrape_airport_list)

    def scrape_airport_list(self, response):
        table = response.xpath('//div/table')
        tbody =  table.xpath('.//tbody')
        airport_links = tbody.xpath('.//tr/td[2]//a/@href').getall() # limit here typically
        ### only getting 50 here!!

        # for ad in ads:....
        for row in airport_links:
            #link = row.get()
            #print(row)
            yield SplashRequest(url=row, callback=self.parse_product, dont_filter=False)


    def parse_product(self, response):
        print('*'* 70)
        print('I work\n', response.url)
        print('*'* 70)
        arrival_div = response.xpath('//div/section/div/div[2]/div/aside[1]/div[1]')

        times = arrival_div.xpath('.//*[@class="hidden-xs hidden-sm ng-scope"]/td[1]//text()').getall()# very important
        # unique because the first td...very very important
        fl_nums = arrival_div.xpath('.//tr[@class="hidden-xs hidden-sm ng-scope"]/td[2]//a//text()').getall()
        print(times, fl_nums)

        # loop over arrivals and yield nested dict for each airport
        zip_rows = zip(times, fl_nums)
        this_airport_abbv = response.url.split('/')[-1]
        d = collections.defaultdict(dict)
        arr_item = AirMongoArrivalItem()
        for i, row in enumerate(list(zip_rows)):
            #if i <= 2:
            #arr_item = AirMongoArrivalItem()
            arr_item['this_airport_initials'] = this_airport_abbv
            arr_item['arrival_{}'.format(i)] = row

        yield arr_item
        #print(arr_item)
