# 6-7-21
# kZ

"""Given the string, check if it is a palindrome.
Example:
- For inputString = "aabaa", the output should be checkPalindrome(inputString) = true;
- For inputString = "abac", the output should be checkPalindrome(inputString) = false;
- For inputString = "a", the output should be checkPalindrome(inputString) = true."""

"""Method 1 to check if Palindrome"""
def checkPalindromeMethod1(inputString):
    reversedInputString = inputString[::-1]
    return (inputString == reversedInputString)


"""Method 2 to check if Palindrome"""
def checkPalindromeMethod2(inputString):
    # lowercase the input string and remove white space
    inputString = inputString.lower()
    inputString = inputString.replace(" ", "")

    # get reverse of input string
    reversedInputString = inputString[::-1]

    # if input and reversed input are same (palindrome==true)
    return (inputString == reversedInputString)


"""---------------------------------------------------"""
""" Tests for checkPalindromeMethod1 -- Method 1      """
"""---------------------------------------------------"""

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
""" Tests for checkPalindromeMethod2 -- Method 2      """
"""---------------------------------------------------"""

inputString = "hannah"
check1 = checkPalindromeMethod2(inputString)
print(check1)

inputString2 = "kevin"
check2 = checkPalindromeMethod2(inputString2)
print(check2)

# iterate over names and check if they are palindromes
names = ["hannah", "kevin"]
for name in names:
    if checkPalindromeMethod2(name):
        print(f"{name} is a palindrome.")
    else:
        print(f"{name} is not a palindrome")

"""---------------------------------------------------"""
"""             End of program                        """
"""---------------------------------------------------"""
