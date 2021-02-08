"""
Database models.
--> Reminder: One (Voter) to Many (Response)
"""
from flask_login import UserMixin
from werkzeug.security import check_password_hash, generate_password_hash

from flask_login import UserMixin
from sqlalchemy import Binary, Column, Integer, String, ForeignKey

from myapp import db

class Voter(db.Model):
    id = db.Column(db.Integer, primary_key=True)
    name = db.Column(db.String(100), index=True)
    email = db.Column(db.String(254), index=True, unique=True)

    # relationship (plural of child class)
    responses = db.relationship('Response',
    backref='voter')

    def __repr__(self):
        return '<Voter {},{}, {}>'.format(self.id, self.name, self.email)

# class (singular)
class Response(db.Model):
    id = db.Column(db.Integer, primary_key=True)
    comment = db.Column(db.String(500))
    age = db.Column(db.Integer)
    radios = db.Column(db.String(20))
    voter_id = db.Column(db.Integer, db.ForeignKey('voter.id'))

    def __repr__(self):
        return '<Comment {},{}, {}>'.format(self.id, self.comment, self.voter_id)
