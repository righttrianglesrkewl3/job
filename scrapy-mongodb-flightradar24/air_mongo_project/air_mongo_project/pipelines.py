# Define your item pipelines here
#
# Don't forget to add your pipeline to the ITEM_PIPELINES setting
# See: https://docs.scrapy.org/en/latest/topics/item-pipeline.html


# useful for handling different item types with a single interface
from itemadapter import ItemAdapter
# add-on imports from stack spider
import pymongo
from scrapy.conf import settings
from scrapy.exceptions import DropItem
from scrapy import log

# default pipeline class
# class AirMongoProjectPipeline:
#     def process_item(self, item, spider):
#         return item

class MongoDBPipeline(object):
    pass
