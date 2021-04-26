# from task_list import db
from application import db

class Todo(db.Model):
    id = db.Column(db.Integer, primary_key=True)
    todo_text = db.Column(db.Text(), nullable=False)
    complete = db.Column(db.Boolean, default=False)
    def __repr__(self):
        return '<Task: {}>'.format(self.text)
        return '<Status: {}>'.format(self.complete)