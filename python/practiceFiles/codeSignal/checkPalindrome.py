# 6-7-21
# kZ

# This program contains two seperate implmentations of functions which check if an input string is a palindrome -- aka it is spelled the same forwards and backwards (e.g. "hannah")


"""Method 1 to check if Palindrome"""
def checkPalindromeMethod1(inputString):
    reversedInputString = inputString[::-1]
    return (inputString == reversedInputString)


"""Method 2 to check if Palindrome"""
def checkPalindromeMethod2(inputString):
    # remove white space and lowercase the input string
    inputString = inputString.replace(" ", "")
    inputString = inputString.lower()

    # get reverse of input string
    reverseInputString = inputString[::-1]

    # check if input and reversed input are the same (palindrome)
    if (inputString == reverseInputString):
        return True
    else:
        return False


"""---------------------------------------------------"""
""" Tests for checkPalindromeMethod1 -- Method 1 """

inputString = "hannah"
check1 = checkPalindromeMethod1(inputString)
print(check1)

inputString2 = "kevin"
check2 = checkPalindromeMethod1(inputString2)
print(check2)

# iterate over names and check if they are palindromes
names = ["hannah", "kevin"]
for name in names:
    if checkPalindromeMethod1(name) == True:
        print(f"{name} is a palindrome.")
    else:
        print(f"{name} is not a palindrome.")

"""---------------------------------------------------"""

""" Tests for checkPalindromeMethod2 -- Method 2 """
inputString = "hannah"
check1 = checkPalindromeMethod2(inputString)
print(check1)

inputString2 = "kevin"
check2 = checkPalindromeMethod2(inputString2)
print(check2)

# iterate over names and check if they are palindromes
names = ["hannah", "kevin"]
for name in names:
    if checkPalindromeMethod2(inputString) == True:
        print(f"{name} is a palindrome.")
    else:
        print(f"{name} is not a palindrome")

"""---------------------------------------------------"""
