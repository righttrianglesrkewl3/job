"""Initialize Flask app."""
import os
from flask import Flask
from flask_sqlalchemy import SQLAlchemy
import flask_excel


db = SQLAlchemy()

def create_app():
    """Construct core Flask app."""
    app = Flask(__name__, instance_relative_config=False)
    app.config.from_object('config.Config')
    
    # Initialize plugins
    db.init_app(app)
    flask_excel.init_excel(app)

    with app.app_context():
        # Import parts of our flask_assets_tutorial
        from .main import main_view
        
        # Register Blueprints
        app.register_blueprint(main_view.main)

        # Create database tables for our data models
        db.create_all()
        return app
