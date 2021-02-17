import scrapy
from scrapy_splash import SplashRequest
import os
from scrapy.linkextractors import LinkExtractor
from scrapy.spiders import Rule, CrawlSpider
from scrapy.http import FormRequest
from scrapy.http import Request
# LOCAL_FILENAME = 'hdb_homepage.html'
# LOCAL_FOLDER = 'html_files'
# BASE_DIR = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
# sudo docker pull scrapinghub/splash
# sudo docker run -p 8050:8050 scrapinghub/splash

class RealHdbSpiSpider(scrapy.Spider):
    name = 'get_html_other_project'
    #start_urls = ['https://www.hockeydb.com']
    start_urls = ['https://www.flightradar24.com/data/airports/abi']
    #start_urls = [f"file://{BASE_DIR}/{LOCAL_FOLDER}/{LOCAL_FILENAME}"]

    def start_requests(self):
        print('***' * 20)
        print('@start requests fxn..')
        yield SplashRequest(
            url=self.start_urls[0],
            callback=self.parse,
        )

    def parse(self, response):
        print('***'* 20)
        print('@parse fxn... url = ', response.url)

        print('[INFO] Writing html to file...')
        with open('splash_enabled_abi_airport_homepage.html', 'wb') as html_file:
            html_file.write(response.body)
