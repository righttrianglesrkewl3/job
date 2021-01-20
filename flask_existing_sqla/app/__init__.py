# from flask import Flask
# from flask_migrate import Migrate, MigrateCommand
# from flask_mail import Mail, Message
# from flask_sqlalchemy import SQLAlchemy
# from flask_script import Manager, Command, Shell
# from flask_login import LoginManager
# import os, config
#
# # initializes extensions
# db = SQLAlchemy()
# mail = Mail()
# migrate = Migrate()
# login_manager = LoginManager()
# login_manager.login_view = 'main.login'
#
# # application factory
# def create_app(config):
#
#     # create application instance
#     app = Flask(__name__)
#     app.config.from_object(config)
#
#     db.init_app(app)
#     mail.init_app(app)
#     migrate.init_app(app, db)
#     login_manager.init_app(app)
#
#     from .main import main as main_blueprint
#     app.register_blueprint(main_blueprint)
#
#     #from .admin import main as admin_blueprint
#     #app.register_blueprint(admin_blueprint)
#
#     return app
# -*- encoding: utf-8 -*-
"""
License: MIT
Copyright (c) 2019 - present AppSeed.us
"""

from flask import Flask, url_for
from flask_login import LoginManager
from flask_sqlalchemy import SQLAlchemy
from importlib import import_module
from os import path

from flask import Flask
from flask_migrate import Migrate, MigrateCommand
from flask_mail import Mail, Message
from flask_sqlalchemy import SQLAlchemy
from flask_script import Manager, Command, Shell
from flask_login import LoginManager
import os, config

# initializes extensions
db = SQLAlchemy()
mail = Mail()
migrate = Migrate()
login_manager = LoginManager()
login_manager.login_view = 'main.login'

# db = SQLAlchemy()
# login_manager = LoginManager()

def register_extensions(app):
    db.init_app(app)
    migrate.init_app(app, db)
    login_manager.init_app(app)

def configure_database(app):

    @app.before_first_request
    def initialize_database():
        db.create_all()

    @app.teardown_request
    def shutdown_session(exception=None):
        db.session.remove()

def create_app():
    app = Flask(__name__, instance_relative_config=False)
    app.config.from_object('config.Config')

    register_extensions(app)

    with app.app_context():
        from .main import main as main_blueprint
        app.register_blueprint(main_blueprint)

        configure_database(app)

        return app
