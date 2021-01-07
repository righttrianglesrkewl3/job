import scrapy
from scrapy_splash import SplashRequest
import os
import collections #default dict nested dict yield item
from scrapy.linkextractors import LinkExtractor
from scrapy.spiders import Rule, CrawlSpider
from scrapy.http import FormRequest
from scrapy.http import Request
from real_hdb_project.items import RealHdbProjectItem

LOCAL_FILENAME = 'homepage_splash_enabled_hdb_homepage.html'
LOCAL_FOLDER = 'html_files'
BASE_DIR = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
#/home/batman/Desktop/py/dec20_real_hdb_env_top/real_hdb_project/homepage_splash_enabled_hdb_homepage.html

class RealHdbSpiSpider(scrapy.Spider):
    name = 'real_hdb_spy'
    start_urls = ['https://www.hockeydb.com/']
    #start_urls = [f"file://{BASE_DIR}/{LOCAL_FOLDER}/{LOCAL_FILENAME}"]
    custom_settings = {"FEEDS": {"hockey_db_results_10_15_20.csv": {"format": "csv"}},'CONCURRENT_REQUESTS': 5}
    try:
        os.remove('hockey_db_results_10_15_20.csv')
    except OSError:
        pass

    def start_requests(self):
        print('***' * 20)
        print('@start requests fxn..')
        print('***' * 20)
        yield SplashRequest(
            url=self.start_urls[0],
            callback=self.scrape_front_page)

    def scrape_front_page(self, response):
        top_1hr = response.xpath('//div[@id="top1hr"]//div[@class="ti tl"]//a/@href').getall()
        for link in top_1hr:
            print(link)
            yield SplashRequest(url=response.urljoin(link), callback=self.parse_top_1hr)


        top_1day = response.xpath('//div[@id="top1day"]//div[@class="ti tl"]//a/@href').getall()
        for link in top_1day:
            print(link)
            yield SplashRequest(url=response.urljoin(link), callback=self.parse_top_1day)

    def parse_top_1hr(self, response):
        print('***' * 20)
        print('@@@ [parse top_1hr] fxn... url = ', response.url)
        print('***' * 20)

        #div = response.xpath('//*[@id="mt"]//h1//text()') # didn't really help this time
        headers = response.xpath('//*[@id="mt"]//table[1]/thead//th//text()').getall()[3:] # dont want first two (regularseason / playoffs)
        stats_table = response.xpath('//*[@id="mt"]//table[1]') # stats table is first of two tables with this class type
        rows = stats_table.xpath('.//tbody//tr')

        player_name = response.xpath('//*[@id="mt"]//h1//text()').get() # only use get because want string not list this will be dict key for all seasons
        time_type = 'parse_top_1hr'
        seasons = rows.xpath('.//td[1]//text()').getall()
        teams = rows.xpath('.//td[2]//a//text()').getall()
        league = rows.xpath('.//td[3]//text()').getall()
        zip_rows = zip(seasons, teams, league)

        item = RealHdbProjectItem()
        for row in zip_rows:
            item['time_type'] = time_type
            item['seasons'] = row[0]
            item['teams'] = row[1]
            item['league'] = row[2]
            item['player_name'] = player_name
            yield item

    def parse_top_1day(self, response):
        print('***' * 20)
        print('@@@ [parse top_1hr] fxn... url = ', response.url)
        print('***' * 20)

        #div = response.xpath('//*[@id="mt"]//h1//text()') # didn't really help this time
        headers = response.xpath('//*[@id="mt"]//table[1]/thead//th//text()').getall()[3:] # dont want first two (regularseason / playoffs)
        stats_table = response.xpath('//*[@id="mt"]//table[1]') # stats table is first of two tables with this class type
        rows = stats_table.xpath('.//tbody//tr')

        player_name = response.xpath('//*[@id="mt"]//h1//text()').get() # only use get because want string not list this will be dict key for all seasons
        time_type = 'parse_top_1day'
        seasons = rows.xpath('.//td[1]//text()').getall()
        teams = rows.xpath('.//td[2]//a//text()').getall()
        league = rows.xpath('.//td[3]//text()').getall()
        zip_rows = zip(seasons, teams, league)

        item = RealHdbProjectItem()
        for row in zip_rows:
            item['time_type'] = time_type
            item['seasons'] = row[0]
            item['teams'] = row[1]
            item['league'] = row[2]
            item['player_name'] = player_name
            yield item




















# In [110]:         player_name = response.xpath('//*[@id="mt"]//h1//text()').geta
#      ...: ll()
#      ...:         seasons = rows.xpath('.//td[1]//text()').getall()
#      ...:         teams = rows.xpath('.//td[2]//a//text()').getall()
#      ...:         games_played = rows.xpath('.//td[4]//text()').getall()
#      ...:         zip_rows = zip(seasons, teams, games_played)
#      ...:
#      ...:         #item = RealHdbProjectItem()
#      ...:         d = dict()
#      ...:         for i, row in enumerate(zip_rows):
#      ...:             print(row[0])
#      ...:             #item['player_name'] = player_name
#      ...:             # item['seasons'] = row[2]
#      ...:             # item['teams'] = row[2]
#      ...:             # item['games_played'] = row[3]
#      ...:             #yield item
#      ...:             d['season_{}'.format(i)] = row[0]
#      ...:             print(d)
#      ...:
#      ...:
#      ...:
# 1998-99
# {'season_0': '1998-99'}
#

            ########################
        # item = RealHdbProjectItem()
        # # item['seasons'] =
        # item['seasons'] = rows.xpath('.//td[1]//text()').getall()
        # item['teams'] = rows.xpath('.//td[2]//a//text()').getall()
        # item['games_played'] = rows.xpath('.//td[4]//text()').getall()
        # item['goals'] = rows.xpath('.//td[5]//text()').getall()
        #
        # yield item


        ########################################## look at Scrapy-Tutu
        # item = RealHdbProjectItem()
        # rows = stats_table.xpath('.//tbody') # need to go "up" a level heirarchy so can split by tr rows then sub select and assign cols
        # for tr in rows.xpath('.//tr'):
        #     item['season'] = tr.xpath('.//td[2]//text()').getall()
        #     season = row.xpath('.//td[1]').get()
        #     team = row.xpath('.//td[2]//a//text()').get()
        #     games_played = row.xpath('.//td[4]//text()').get()
        #     goals = row.xpath('.//td[5]//text()').get()
