"""Initialize Flask app."""
from flask import Flask
from flask_sqlalchemy import SQLAlchemy

db = SQLAlchemy()

def create_app():
    """Construct core Flask app."""
    app = Flask(__name__, instance_relative_config=False)
    app.config.from_object('config.Config')

    # Initialize plugins
    db.init_app(app)

    with app.app_context():
        # Import parts of our flask_assets_tutorial
        from .main import main_views

        # Register Blueprints
        # app.register_blueprint(admin_routes.admin_bp)
        app.register_blueprint(main_views.main)

        # Create database tables for our data models
        db.create_all()
        return app
