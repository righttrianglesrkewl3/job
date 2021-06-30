# 6-30-21
# kZ
"""
We have two monkeys, a and b, and the parameters a_smile and b_smile indicate if each is smiling. We are in trouble if they are both smiling or if neither of them is smiling. Return True if we are in trouble.


monkey_trouble(True, True) → True
monkey_trouble(False, False) → True
monkey_trouble(True, False) → False
"""

#if (a and b) or (not a and not b)
def monkey_trouble(a_smile, b_smile):
    bool_trouble = False
    
    if (a_smile and b_smile) or (not a_smile and not b_smile):
        bool_trouble = True

    return bool_trouble

# tests
print(monkey_trouble(True, True))
print(monkey_trouble(True, True))
print(monkey_trouble(True, False))
