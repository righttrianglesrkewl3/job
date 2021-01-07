from flask import Blueprint
from flask import current_app as app#?
from flask import render_template

# Blueprint Configuration
chart_bp = Blueprint(
    "chart_bp", __name__,
        template_folder='templates',
        static_folder='static')

@chart_bp.route('/process')
def process():
    return render_template('dashboard.jinja2')
