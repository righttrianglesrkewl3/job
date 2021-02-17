import scrapy
import datetime
from scrapy_splash import SplashRequest
import os
import collections #default dict nested dict yield item
from scrapy.linkextractors import LinkExtractor
from scrapy.spiders import Rule, CrawlSpider
from scrapy.http import FormRequest
from scrapy.http import Request
from weather_project.items import WeatherProjectItem

class WeatherSpiSpider(scrapy.Spider):
    name = 'weather_spi'
    start_urls = ['https://www.aviationweather.gov/sigmet/data?hazard=all/']

    custom_settings = {"FEEDS": {"weather_results_1_16_21.csv": {"format": "csv"}},'CONCURRENT_REQUESTS': 5}

    try:
        os.remove('weather_results_1_16_21.csv')
    except OSError:
        pass

    def start_requests(self):
        yield SplashRequest(
            url=self.start_urls[0],
            callback=self.parse_weather)

    def parse_weather(self, response):
        print('*'*50)
        print('@ parse_weather fxn with url = {}'.format(response.url))
        print('*'*50)

        # select stuff you want
        div = response.xpath('//div[@id="content"]')
        type = [i.replace('\n','') and i.replace('Type: ','') for i in div.xpath('.//span//text()').getall()]
        content = [i.replace('\n','') for i in div.xpath('.//pre//text()').getall()]

        # zip up each column of "selectors"... then loop and toss into item (inside loop init)
        zip_rows = zip(type, content)
        for row in zip_rows:
            item = WeatherProjectItem()
            item['type'] = row[0]
            item['content'] = row[1]

            yield item
