"""
Given a string, return a new string where "not " has been added to the front. However, if the string already begins with "not", return the string unchanged.


not_string('candy') → 'not candy'
not_string('x') → 'not x'
not_string('not bad') → 'not bad'
"""

def not_string(some_string):
    if some_string.startswith("not ") or (some_string == "not"):
        return some_string
    else:
        return ("not " + some_string)

print(not_string('candy'))
print(not_string('x'))
print(not_string("not bad"))
print(not_string("not"))

def not_string_refactor1(some_string):
    if len(some_string) >= 3 and some_string[:3] == "not":
        return some_string
    return "not " + some_string
     # str[:3] goes from the start of the string up to but not
    # including index 3

print(not_string_refactor1('candy'))
print(not_string_refactor1('x'))
print(not_string_refactor1("not bad"))
print(not_string_refactor1("not"))
