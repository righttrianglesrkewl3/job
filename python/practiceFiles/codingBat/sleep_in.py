# 6-30-21
# kZ

"""
The parameter weekday is True if it is a weekday, and the parameter vacation is True if we are on vacation. We sleep in if it is not a weekday or we're on vacation. Return True if we sleep in.


sleep_in(False, False) → True
sleep_in(True, False) → False
sleep_in(False, True) → True
"""

def sleep_in(weekday, vacation):
    bool_sleep = False
    if weekday != True or vacation == True:
        bool_sleep = True

    return bool_sleep

print(sleep_in(weekday=False, vacation=False))
print(sleep_in(weekday=True, vacation=False))
print(sleep_in(weekday=False, vacation=True))
