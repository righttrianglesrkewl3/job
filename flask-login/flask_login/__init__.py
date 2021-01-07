from flask import Flask
from flask_assets import Environment
from flask import current_app as app

def init_app():
    """Create Flask application."""
    app = Flask(__name__, instance_relative_config=False)
    app.config.from_object("config.Config")

    from .auth import auth
    from .chart import chart

    app.register_blueprint(auth.auth_bp)
    app.register_blueprint(chart.chart_bp)

    return app
