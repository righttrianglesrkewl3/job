"""
Given an int n, return True if it is within 10 of 100 or 200. Note: abs(num) computes the absolute value of a number.


near_hundred(93) → True
near_hundred(90) → True
near_hundred(89) → False
"""

def near_hundred(n):
    cond1 = abs(100 - n) <= 10
    cond2 = abs(200 - n) <= 10

    if cond1 or cond2:
        return True
    else:
        return False

def near_hundred_refactor1(n):
    cond1 = abs(100 - n) <= 10
    cond2 = abs(200 - n) <= 10

    return cond1 or cond2

def near_hundred_refactor2(n):
    return (abs(100 - n) <= 10) or (abs(200 - n) <= 10)

checks = [93, 90, 89]
for c in checks:
    print(f"near hundred? {c} answer: {near_hundred(c)}")
    print(f"near hundred? {c} answer: {near_hundred_refactor1(c)}")
    print(f"near hundred? {c} answer: {near_hundred_refactor2(c)}")
