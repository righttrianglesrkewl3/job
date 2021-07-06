"""Given 2 int values, return True if one is negative and one is positive. Except if the parameter "negative" is True, then return True only if both are negative.


pos_neg(1, -1, False) → True
pos_neg(-1, 1, False) → True
pos_neg(-4, -5, True) → True
"""

# doesnt pass all tests (keeping for reference)
def pos_neg(a, b, negative=False):
    if negative == True:
        #return (a < 0 and b < 0)
        cond1 = (a < 0 and b < 0)
        return cond1
    elif ((a > 0) or (b < 0)) or ((a < 0) or (b > 0)):
        return True

print(pos_neg(1, -1, False))
print(pos_neg(-1, 1, False))
print(pos_neg(-4, -5, True))

# doesnt pass all tests (keeping for reference)
def pos_neg_refactor1(a, b, negative=False):
    if negative == True:
        return (a < 0 and b < 0)
    return ((a > 0) or (b < 0)) or ((a < 0) or (b > 0))


print(pos_neg_refactor1(1, -1, False))
print(pos_neg_refactor1(-1, 1, False))
print(pos_neg_refactor1(-4, -5, True))

# passes all tests
def pos_neg_refactor2(a, b, negative):
  if negative:
    return (a < 0 and b < 0)
  else:
    return ((a < 0 and b > 0) or (a > 0 and b < 0))

print(pos_neg_refactor2(1, -1, False))
print(pos_neg_refactor2(-1, 1, False))
print(pos_neg_refactor2(-4, -5, True))
