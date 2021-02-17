import scrapy
from scrapy_splash import SplashRequest
import os

# LOCAL_FILENAME = 'hdb_homepage.html'
# LOCAL_FOLDER = 'html_files'
# BASE_DIR = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))

class RealHdbSpiSpider(scrapy.Spider):
    name = 'real_hdb_spi'
    start_urls = ['https://www.hockeydb.com']
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
        with open('hdb_homepage.html', 'wb') as html_file:
            html_file.write(response.body)
