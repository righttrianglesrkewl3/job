import scrapy
from scrapy_splash import SplashRequest
import os
import collections #default dict nested dict yield item
from scrapy.linkextractors import LinkExtractor
from scrapy.spiders import Rule, CrawlSpider
from scrapy.http import FormRequest
from scrapy.http import Request
from hockey_ref_project.items import HockeyRefProjectItem
from string import ascii_lowercase

class HrefSpiderSpider(scrapy.Spider):
    name = 'href_spider'
    start_urls = ['https://www.hockey-reference.com']
    custom_settings = {"FEEDS": {"href_results.csv": {"format": "csv"}},'CONCURRENT_REQUESTS': 5}

    try:
        os.remove('href_results.csv')
    except OSError:
        pass

    def start_requests(self):
        print('***' * 20)
        print('@start requests fxn..')
        print('***' * 20)

        yield SplashRequest(
            url=self.start_urls[0],
            callback=self.nav_to_letters)

    def nav_to_letters(self, response):
        print('***' * 20)
        print('@nav_to_letters fxn..')
        print('***' * 20)
        #letters = '/players/a/'
        for c in ascii_lowercase:
            if c == 'c':
                letter = '/players/{}/'.format(c)

                yield SplashRequest(
                    url=response.urljoin(letter),
                    callback=self.grab_players_for_letter)

    def grab_players_for_letter(self, response):
        player_links = response.xpath('.//*[@id="all_players"]//p//a//@href').getall()

        for link in player_links:
            yield SplashRequest(
                url=response.urljoin(link),
                callback=self.parse_me,
            )

    def parse_me(self, response):
        print('***' * 20)
        print('@parse_me fxn..')
        print('***' * 20)
        print(response.url)
        anchor = response.xpath('//div[@id="meta"]') or "no value present"

        if anchor.xpath('.//div[@class="nothumb"]'):
            print('[INFO]---> NO EXTRA')

        name = anchor.xpath('.//h1//span//text()').get()
        current_team = anchor.xpath('.//p[3]//span//text()').get()
        height = anchor.xpath('.//p[2]//span[1]//text()').get()
        weight = anchor.xpath('.//p[2]//span[2]//text()').get()
        born_date = anchor.xpath('.//p[4]//span//a[1]//text()').get() or anchor.xpath('.//p[3]//span//a[1]//text()').get()
        born_year = anchor.xpath('.//p[4]//span//a[2]//text()').get() or anchor.xpath('.//p[3]//span//a[2]//text()').get()

        # rows = zip(name, current_team, height, weight)

        item = HockeyRefProjectItem()
        item['name'] = name
        item['current_team'] = current_team
        item['height'] = height
        item['weight'] = weight
        item['born_date'] = born_date
        item['born_year'] = born_year

        yield item
