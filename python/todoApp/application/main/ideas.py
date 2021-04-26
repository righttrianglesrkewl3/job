"""
Another possible solution specially if you want batch delete

deleted_objects = User.__table__.delete().where(User.id.in_([1, 2, 3]))
session.execute(deleted_objects)
session.commit()
"""