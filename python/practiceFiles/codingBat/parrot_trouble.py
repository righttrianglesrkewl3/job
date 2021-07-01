"""We have a loud talking parrot. The "hour" parameter is the current hour time in the range 0..23. We are in trouble if the parrot is talking and the hour is before 7 or after 20. Return True if we are in trouble.


parrot_trouble(True, 6) → True
parrot_trouble(True, 7) → False
parrot_trouble(False, 6) → False
"""

# Notes:
# don't mess up or confuse the order of the arugments into the function
# inequalities
# Need extra parenthesis around the or clause
# since and binds more tightly than or.
# important: and binds more tightly than or.
# and is like arithmetic *, or is like arithmetic +




# (7 > hour > 20) and (talking == True)
# ^ why can't I do this?




def parrot_trouble(talking, hour):
    hourBool = True if (hour < 7) or (hour > 20) else False
    talkingBool = talking
    troubleBool = True if (hourBool and talkingBool) == True else False
    return troubleBool

"""def THIS_WONT_WORK(talking, hour):
    return True if (hour < 7) or (hour > 20) and talking else False

Reason below.
# Need extra parenthesis around the or clause
  # since and binds more tightly than or.
  # and is like arithmetic *, or is like arithmetic +
"""

def parrot_refactor(talking, hour):
    return True if ((hour < 7) or (hour > 20)) and talking else False


def parrot_refactor_sourcery(talking, hour):
    return bool(((hour < 7) or (hour > 20)) and talking)

# parrot_trouble
print(parrot_trouble(True, 6))
print(parrot_trouble(True, 7))
print(parrot_trouble(False, 6))
print("\n")

# parrot_refactor
print(parrot_refactor(True, 6))
print(parrot_refactor(True, 7))
print(parrot_refactor(False, 6))
print("\n")

# parrot_refactor_sourcery
print(parrot_refactor_sourcery(True, 6))
print(parrot_refactor_sourcery(True, 7))
print(parrot_refactor_sourcery(False, 6))


"""Solution:
def parrot_trouble(talking, hour):
  return (talking and (hour < 7 or hour > 20))
  # Need extra parenthesis around the or clause
  # since and binds more tightly than or.
  # and is like arithmetic *, or is like arithmetic +"""
