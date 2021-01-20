from flask_wtf import FlaskForm
from wtforms import PasswordField, StringField, SubmitField, TextAreaField
from wtforms.validators import DataRequired, Email, EqualTo, Length, Optional

# If your app (blueprint form) uses forms then define them in this file
# class PostForm(FlaskForm):
#     title = StringField('Title', validators=[DataRequired()])
#     content = TextAreaField('Content',
#                       validators=[DataRequired(), Length(min=2, max=50)])
#     submit = SubmitField('Post')
