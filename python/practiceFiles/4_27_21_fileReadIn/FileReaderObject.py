from datetime import datetime
from tabulate import tabulate

class FileReader():
    def __init__(self, filePath, wordCount=0):
        self.filePath = filePath
        self.wordCount = wordCount

    def readin(self):
        with open(self.filePath) as f:
            text = f.readlines()
            for line in text:
                print(line)
                
    def __repr__(self):
        data = {"Word Count:": [self.wordCount],
                "Time:" : [datetime.now()]}
        table = tabulate(data, headers="keys", tablefmt="pretty")
        return table

if __name__ == "__main__":
    print(FileReader('mbox-short.txt'))


"""
Output for: python3 testObjectPython.py 
+-------------+------ ----------------------+
| Word Count: |           Time:            |
+-------------+----------------------------+
|      0      | 2021-04-27 15:39:12.688505 |
+-------------+----------------------------+
"""
