# Define here the models for your scraped items
#
# See documentation in:
# https://docs.scrapy.org/en/latest/topics/items.html

import scrapy


class AirMongoProjectItem(scrapy.Item):
    r1_apt_name = scrapy.Field()
    rank = scrapy.Field()
    r1_flights_per_week = scrapy.Field()
    this_airport = scrapy.Field()
    metar_link = scrapy.Field()

    # from metar page
    day = scrapy.Field()
    time  = scrapy.Field()
    wind_direction = scrapy.Field()
    wind_speed = scrapy.Field()
    temperature = scrapy.Field()
    dew_point = scrapy.Field()
    pressure = scrapy.Field()
    visibility = scrapy.Field()

class AirMongoArrivalItem(scrapy.Item):
    arrival_0 = scrapy.Field()
    arrival_1 = scrapy.Field()
    arrival_2 = scrapy.Field()
    arrival_3 = scrapy.Field()
    arrival_4 = scrapy.Field()
    arrival_5 = scrapy.Field()
    arrival_6 = scrapy.Field()
    arrival_7 = scrapy.Field()
    this_airport_initials = scrapy.Field()
