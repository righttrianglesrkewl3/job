from os import environ, path
from app import db, login_manager
from flask_login import (LoginManager, UserMixin, login_required,
                          login_user, current_user, logout_user)
from werkzeug.security import generate_password_hash, check_password_hash

from sqlalchemy import create_engine
from sqlalchemy.orm import scoped_session, sessionmaker
engine = create_engine('sqlite:////home/batman/Desktop/flask_app-master/real_weather_data.db')
Session = scoped_session(sessionmaker(bind=engine))


class Weather(db.Model):
    __tablename__ = 'weather_data'
    id = db.Column(db.Integer(), primary_key=True)
    type = db.Column(db.String(255), nullable=False)
    content = db.Column(db.String(255), nullable=False)


    def __repr__(self):
        return "<{}:{}>".format(self.id, self.dtime, self.type, self.content)
