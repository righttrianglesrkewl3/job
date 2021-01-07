import scrapy
from nytcoverspider.items import NytcoverspiderItem

class Nytcoverspider(scrapy.spiders.Spider):
    name = "nyt_spider"
    start_urls = ["http://nytimes.com/"]

    def parse(self, response):
        image = NytcoverspiderItem()
        img_urls = []
        links = response.xpath('//img/@src')
        #links = response.xpath('//*[@id="news-feed"]')

        for link in links:
            # Extract the URL text from the element
            url = link.get()

            if any(extension in url for extension in ['.jpg', '.gif', '.png']):
                #and not any(domain in url for domain in ['nytimesstatic.com']):
                img_urls.append(url)

        image["image_urls"] = img_urls

        return image
