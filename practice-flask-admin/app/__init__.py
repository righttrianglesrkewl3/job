from flask import Flask, url_for
from flask_login import LoginManager
from flask_sqlalchemy import SQLAlchemy
from importlib import import_module
from os import path

db = SQLAlchemy()
login_manager = LoginManager()

def register_extensions(app):
    db.init_app(app)
    login_manager.init_app(app)

def register_blueprints(app):
    for module_name in ('base', 'home'):
        module = import_module('app.{}.routes'.format(module_name))
        app.register_blueprint(module.blueprint)

def configure_database(app):

    @app.before_first_request
    def initialize_database():
        db.create_all()

    @app.teardown_request
    def shutdown_session(exception=None):
        db.session.remove()

def create_app():
    #app = Flask(__name__, static_folder='base/static')
    app = Flask(__name__, instance_relative_config=False)
    app.config.from_object('config.Config')

    register_extensions(app)

    #app.config.from_object(config)
    with app.app_context():
        #register_extensions(app)
        register_blueprints(app)
        configure_database(app)
        #configure_logs(app)
        #apply_themes(app)
        return app
