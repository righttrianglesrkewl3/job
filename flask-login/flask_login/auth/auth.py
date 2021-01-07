from flask import Blueprint
from flask import current_app as app#?
from flask import render_template
from flask import request
from flask import redirect
from flask import url_for

# Blueprint Configuration
auth_bp = Blueprint(
    "auth_bp", __name__,
        template_folder='templates',
        static_folder='static')

@auth_bp.route('/')
def index():
    return render_template('login.jinja2',
    title='Signin Template · Bootstrap v5.0')

@auth_bp.route('/sign')
def sign():
    return render_template('sign.jinja2')

@auth_bp.route('/process', methods=['POST'])
def process():
    name = request.form['name']
    return render_template('process.jinja2', name=name)

@auth_bp.route('/second_process', methods=['POST'])
def second_process():
    username = request.form['username']
    password = request.form['password']

    return render_template('second_process.jinja2', username=username, password=password)
