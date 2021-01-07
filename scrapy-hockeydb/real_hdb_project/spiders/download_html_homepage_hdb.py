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
    name = 'download_two_html'
    #start_urls = ['https://www.hockeydb.com/']
    start_urls = ['https://www.hockeydb.com/ihdb/stats/pdisplay.php?filter=Y&pid=130608']
    #start_urls = [f"file://{BASE_DIR}/{LOCAL_FOLDER}/{LOCAL_FILENAME}"]
    #self.counter = 0
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
        with open('{}_splash_enabled_one_player_homepage.html'.format('murray'), 'wb') as html_file:
            html_file.write(response.body)
        #self.counter+=1
