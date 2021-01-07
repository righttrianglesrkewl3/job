# -*- encoding: utf-8 -*-
"""
License: Commercial
Copyright (c) 2019 - present AppSeed.us
"""

from flask_migrate import Migrate
from os import environ
from sys import exit

from app import create_app, db


app = create_app()
Migrate(app, db)

if __name__ == "__main__":
    app.run()
