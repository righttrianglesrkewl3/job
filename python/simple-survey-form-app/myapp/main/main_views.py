"""Main Views/Routes."""
from flask import Blueprint, render_template, make_response, redirect, url_for, current_app

from myapp.main.main_forms import SurveyForm
from myapp.models import Voter, Response, db

main = Blueprint('main', __name__)

@main.route('/', methods=['GET', 'POST'])
def main_index():
    form = SurveyForm()
    if form.validate_on_submit():
        # grab stuff from form
        voter = Voter(name=form.name.data,
        email=form.email.data)

        # db logic goes here
        db.session.add(voter)
        db.session.commit()

        #NOTE: dont get id of voter until added to db..thats why need to add/commit twice
        response = Response(comment=form.text_area.data, voter_id=voter.id, age=form.age.data, radios=form.radios.data) # from voter above

        # db logic goes here
        db.session.add(response)
        db.session.commit()

        # commit and ...
        return redirect(url_for('main.show'))


    title = 'Some Awesome Title!'

    return render_template('form.html',
    form=form, title=title)

@main.route('/show', methods=['GET', 'POST'])
def show():
    voters = db.session.query(Voter).all()

    return render_template('users.html', voters=voters)
