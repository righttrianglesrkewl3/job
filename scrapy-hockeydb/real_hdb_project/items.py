# Define here the models for your scraped items
#
# See documentation in:
# https://docs.scrapy.org/en/latest/topics/items.html

import scrapy


class RealHdbProjectItem(scrapy.Item):
    # define the fields for your item here like:
    # name = scrapy.Field()
    seasons = scrapy.Field()
    teams = scrapy.Field()
    league = scrapy.Field()
    player_name = scrapy.Field()
    time_type = scrapy.Field()
