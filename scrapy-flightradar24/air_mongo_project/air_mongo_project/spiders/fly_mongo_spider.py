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
    name = 'fly_mongo_spi'
    start_urls = ['https://www.flightradar24.com/']
    custom_settings = {"FEEDS": {"output_files/airport_results_10_14_20.csv": {"format": "csv"}},'CONCURRENT_REQUESTS': 5}

    def parse(self, response):
        # give login creds here
        login_data = {'username': 'username goes here',
                        'password': 'password goes here'
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
        airport_links = tbody.xpath('.//tr/td[2]//a/@href').getall()[:25] # limit here typically .getall()[1:10]
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

        #details_link = response.urljoin(l)
        this_airport = response.url.split('/')[-1] #
        l="/data/airports/{}/weather".format(this_airport)
        metar_link = response.urljoin(l)

        div = response.xpath('//div[2]/div/aside[2]/div[2]')
        ul = div.xpath('.//ul//li[1]//text()').getall()
        if ul:
            print('ul exists', ul)
            print('len of ul = ', len(ul))
            print('printing i for i in ul...\n', [i for i in ul])

            request = SplashRequest(url=metar_link, callback=self.parse_metar,
            cb_kwargs={
            'this_airport' : this_airport,
            'rank' : ul[0],
            'r1_apt_name' : ul[1],
            'r1_flights_per_week' : ul[2] + ul[3],
            'metar_link': metar_link
            })
            yield request

        else:
            #self.metar_pass.append(response.url)
            print('no ul', response.url)


    def parse_metar(self, response, this_airport, rank, r1_apt_name, r1_flights_per_week, metar_link):
        print(this_airport, rank, r1_apt_name, r1_flights_per_week, metar_link)
        print('[INFO] METAR URL  & STATUS RESPONSE = :\n', response.url, response.status)

        tbody = response.xpath('//aside/div[@class="row cnt-schedule-table"]//tbody')
        ul = tbody.xpath('.//tr[2]/td/ul//li/text()').getall()   # looping through each li in ul
        # only get rows with all of the "wanted columns"Request
        if len(ul) == 8:
            # instantiate from items.py file
            item = AirMongoProjectItem()
            item['this_airport'] = this_airport
            item['rank'] = rank
            item['r1_apt_name'] = r1_apt_name
            item['r1_flights_per_week'] = r1_flights_per_week
            item['metar_link'] = metar_link
            item['day'] = ul[0]
            item['time']  = ul[1]
            item['wind_direction'] = ul[2]
            item['wind_speed'] = ul[3]
            item['temperature'] = ul[4]
            item['dew_point'] = ul[5]
            item['pressure'] = ul[6]
            item['visibility'] = ul[7]

            yield item

        else:
            print('------>NO UL', response.url)



#     print(row)
