"""Main Views/Routes."""
import os
import base64
import cv2
import imutils
import numpy as np
from os import environ, path
from flask import Blueprint, render_template, make_response, redirect, url_for, current_app, request, send_from_directory, send_file, flash
from werkzeug.utils import secure_filename
############################################
# from myapp.main.main_forms import SurveyForm
# from myapp.models import Voter, Response, db
from myapp.main.main_forms import UploadForm
from myapp.models import db, ImageFile
from myapp.utils import validate_image
##############################################
# base = '/home/batman/Desktop/py/log_copy_1_17_21/2021/01/flask_all/steganography/copy'
photo_location = '/home/batman/Desktop/py/log_copy_1_17_21/2021/01/flask_all/steganography/photos'
main = Blueprint('main', __name__)

@main.route('/', methods=['GET','POST'])
def index():
    ds = ImageFile.query.all()
    files = os.listdir(current_app.config['UPLOAD_PATH'])

    form = UploadForm()
    if request.method == "POST" and form.validate_on_submit():
        uploaded_file = request.files['file']
        filename = secure_filename(uploaded_file.filename)
        if filename != '':
            # save to /photos
            uploaded_file.save(os.path.join(current_app.config['UPLOAD_PATH'], filename))

            # db logic goes here
            text = form.text.data
            filename = filename # see "if" statement above
            image_file = ImageFile(text=text, filename=filename)
            db.session.add(image_file)
            db.session.commit()
            return redirect(url_for('main.show', img_filename=filename))
    return render_template('index.html', form=form, files=files, ds=ds)
################################################################
#NOTE: need post only route to show original and encoded photo...can't pass data in query string
################################################################
@main.route('/uploads/<filename>')
def upload(filename):
    return send_from_directory(current_app.config['UPLOAD_PATH'], filename)

@main.route('/show/<img_filename>')
def show(img_filename):
    originalImage = cv2.imread(os.path.join(current_app.config['UPLOAD_PATH'], img_filename)).copy()

    # NOTE: process aka "encode right here"
    processed_img = cv2.cvtColor(originalImage, cv2.COLOR_BGR2GRAY)

    # write encoded image to disk
    encoded_filepath = 'encoded_' + img_filename
    cv2.imwrite(os.path.join(current_app.config['UPLOAD_PATH'], encoded_filepath), processed_img)

    return render_template('_show_filename.html', img_filename=img_filename, encoded_filepath=encoded_filepath)

# @main.route('/show')
# def show():
#     all = ImageFile.query.all()
#     # most_recent = ImageFile.query.first()
#     # most_recent_filename = most_recent.filename
#     # most_recent_text = most_recent.text
#     return render_template('_users.html', all=all)
