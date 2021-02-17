"""Simple Survey Form."""
from flask_wtf import FlaskForm
from wtforms import PasswordField, StringField, SubmitField, RadioField, SelectField, SelectMultipleField, TextAreaField
from wtforms.fields.html5 import EmailField, IntegerField
from wtforms.widgets import CheckboxInput, ListWidget
from wtforms.validators import DataRequired, Email, EqualTo, Length, Optional, ValidationError

class SurveyForm(FlaskForm):
    name = StringField('Name', validators=[DataRequired(), Length(max=100)])
    email = EmailField('Email', validators=[DataRequired()])
    age = IntegerField('Age', validators=[DataRequired(),])
    radios = RadioField('Radios', default='new', choices=[('new', 'Existing Client'), ('existing', 'New Client ')])
    text_area = TextAreaField('Comment')
    submit = SubmitField('Submit')
