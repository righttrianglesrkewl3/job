from flask import (
    Blueprint, current_app, flash, make_response, redirect, render_template, request, send_file, send_from_directory, url_for, g
)
import flask_excel

from application.models import db, Todo

main = Blueprint('main', __name__)
@main.before_request
def before_request():
    total_items = Todo.query.count()
    complete_items = Todo.query.filter(Todo.complete == 1).count()
    remaining_items = total_items - complete_items
    g.count = str(remaining_items)

@main.route('/', methods=['GET','POST']) #GET
def index():
    if request.method == 'POST':
        todo_text = request.form['todo_text']
        if not todo_text:
            flash('Task name is required.')
        else:
            db.session.add(Todo(todo_text=todo_text))
            db.session.commit()
            return redirect(url_for('main.index'))

    todo_list = Todo.query.all()
    return render_template('index.html', todo_list=todo_list)

@main.route("/delete/<string:todo_id>", methods=['GET','POST'])
def delete(todo_id):
    todo = Todo.query.filter_by(id=todo_id).first()
    db.session.delete(todo)
    db.session.commit()
    return redirect(url_for("main.index"))

@main.route("/complete/<string:todo_id>", methods=['GET','POST'])
def complete(todo_id):
    todo = Todo.query.filter_by(id=todo_id).first()
    todo.complete = not todo.complete
    db.session.commit()
    return redirect(url_for("main.index"))


@main.route('/index/save_to_disk')
def save_to_disk():
    return flask_excel.make_response_from_array([[1,2], [3, 4]], "csv",
                                          file_name="export_data")

"""
Use as a reference for "add" route
@main.route('/uploads/<filename>')
def upload(filename):
    return send_from_directory(current_app.config['UPLOAD_PATH'], filename)
"""

# @app.route("/", methods=['GET'])
# def export_records():
#     return render_template('export.html')

# @app.route('/save_to_disk')
# def save_to_disk():
#     return flask_excel.make_response_from_array([[1,2], [3, 4]], "csv",
#                                           file_name="export_data")


