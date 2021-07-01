"""Given an int n, return the absolute difference between n and 21, except return double the absolute difference if n is over 21.


diff21(19) → 2
diff21(10) → 11
diff21(21) → 0
"""

# absolute value = distance away from zero
# remember:
# difference between n and 21 means..... 21 - n

def diff21(n):
    if n > 21:
       return abs(21 -n) * 2
    else:
        return abs(21- n)

print(diff21(19))
print(diff21(10))
print(diff21(21))
