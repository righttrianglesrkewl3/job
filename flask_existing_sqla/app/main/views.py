import datetime
from app import db, login_manager
from . import main
from flask import request, render_template, redirect, url_for, flash, make_response, session, current_app
from flask_login import login_required, login_user, current_user, logout_user
from app.models import db, Weather
from .forms import PostForm

##############################
from app.models import Session
session = Session()
########################

# format dates
dt = datetime.datetime.now()
dt = datetime.datetime(dt.year, dt.month, dt.day, dt.hour, dt.minute)

@main.route('/')
def index():
    weather_data = db.session.query(Weather).all()
    return render_template('_users.jinja2', date=dt, weather_data=weather_data, title='Landing Page')

@main.route('/user/<int:user_id>/')
def user_profile(user_id):
    return "Profile page of user #{}".format(user_id)


@main.route('/books/<genre>/')
def books(genre):
    return "All Books in {} category".format(genre)

@login_manager.user_loader
def load_user(user_id):
    """Check if user is logged-in upon page load."""
    if user_id is not None:
        return User.query.get(user_id)
    return None


@login_manager.unauthorized_handler
def unauthorized():
    """Redirect unauthorized users to Login page."""
    flash('You must be logged in to view that page.')
    return redirect(url_for('auth_blueprint.login'))
