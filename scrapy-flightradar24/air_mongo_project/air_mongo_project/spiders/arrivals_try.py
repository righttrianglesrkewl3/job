import scrapy
import collections
import os
# MUST be scrapy.linkextractors with an 's' import LinkExtractor (singular)
from scrapy.linkextractors import LinkExtractor
from scrapy.spiders import Rule, CrawlSpider
from scrapy.http import FormRequest
from scrapy.http import Request
from air_mongo_project.items import AirMongoProjectItem

from scrapy_splash import SplashRequest

# usage
#scrapy crawl <spider name> -o file.csv -t csv

class FlyMongoSpiderSpider(scrapy.Spider):
    name = 'fly_arrivals_spider'
    start_urls = ['https://www.flightradar24.com/']
    custom_settings = {"FEEDS": {"results.csv": {"format": "csv"}},'CONCURRENT_REQUESTS': 5}

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
        one_airport = ['https://www.flightradar24.com/data/airports/abq']

        yield SplashRequest(url=one_airport[0], callback=self.parse_arrivals)

    def parse_arrivals(self, response):
        print('@ parse arrivals fxn')
        arrival_div = response.xpath('//div/section/div/div[2]/div/aside[1]/div[1]')

        times = arrival_div.xpath('.//*[@class="hidden-xs hidden-sm ng-scope"]/td[1]//text()').getall()# very important
        # unique because the first td...very very important
        fl_nums = arrival_div.xpath('.//tr[@class="hidden-xs hidden-sm ng-scope"]/td[2]//a//text()').getall()
        print(times, fl_nums)

        # loop over arrivals and yield nested dict for each airport
        zip_rows = zip(times, fl_nums)
        this_airport_arrivals = response.url.split('/')[-1]
        for i, row in enumerate(list(zip_rows)):
            print(i, row)

        d = collections.defaultdict(dict)
        for i, row in enumerate(list(zip_rows)):
            outer_key = 'airport_{}'.format(i)
            inner_key = 'arrival_{}'.format(i)
            value = row
            print(outer_key,inner_key, value)
            # d[outer_key][inner_key] = row
            # #print(d)
            # print (d)
        #
###################### SAVE ############################
        #print(arrival_div.xpath('//tr[@class="hidden-xs hidden-sm ng-scope"]').getall())

        # "columns"/criteria
        # times = arrival_div.xpath('.//tr[@class="hidden-xs hidden-sm ng-scope"]/td[1]//text()').getall()
        # fl_nums = arrival_div.xpath('.//tr[@class="hidden-xs hidden-sm ng-scope"]/td[2]//a//text()').getall()
        # print('times', times)
        # print('fl_nums', fl_nums)


        # # loop over arrivals and yield nested dict for each airport
        # zip_rows = zip(times, fl_nums)
        # this_airport_arrivals = response.url.split('/')[-1]
        # d = collections.defaultdict(dict)
        # for i, row in enumerate(list(zip_rows)):
        #     outer_key = this_apt
        #     inner_key = 'arrival_{}'.format(i)
        #     value = row
        #     #print(outer_key,inner_key, value)
        #     d[outer_key][inner_key] = row
        #     #print(d)
        #     yield d
