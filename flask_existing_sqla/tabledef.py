import csv
from sqlalchemy import Column, Date, Integer, String, Text, create_engine, DateTime
import datetime
from sqlalchemy.orm import sessionmaker
from sqlalchemy.ext.declarative import declarative_base
from sqlalchemy.sql import func
engine = create_engine('sqlite:///real_weather_data.db', echo=True)
Base = declarative_base()
Session = sessionmaker()

class Weather(Base):
    __tablename__= "weather_data"

    id = Column(Integer, primary_key=True, autoincrement=True, nullable=False)
    type = Column(String, nullable=False)
    content = Column(Text, nullable=False)

    def columns_to_dict(self):
        dict_ = {}
        for key in self.__mapper__.c.keys():
            dict_[key] = getattr(self, key)
        return dict_

Base.metadata.create_all(bind=engine)
Session.configure(bind=engine)

session = Session()
with open("weather_results_1_16_21.csv", "r") as f:
    csv_reader = csv.DictReader(f)

    for row in csv_reader:
        db_record = Weather(
            type=row["type"],
            content=row["content"]
        )
        session.add(db_record)

    session.commit()
