"""
Question source: https://simpleprogrammer.com/programming-interview-questions/
Part of common array-based coding interview questions

1. How do you find the missing number in a given integer array of 1 to 100?

"""

# make list with integers from 1 to 100 
oneToHundredFull = [i for i in range(1, 101)]

# make list with integers from 1 to 100 (except missing one number: 5)
oneToHundredMissing = [i for i in range(1, 101) if i != 5]

# initialize empty list to append mising number to
missingNum = []

for i in range(len(oneToHundredFull)):
    if oneToHundredFull[i] not in oneToHundredMissing:
        missingNum.append(oneToHundredFull[i])

print(missingNum)

########################### Refactored Version of Above ###########################

oneToHundredMissing = [i for i in range(1, 101) if i != 5]
def findMissingInt(oneToHundredMissing):
    oneToHundredFull = [i for i in range(1, 101)]
    return [i for i in oneToHundredFull if i not in oneToHundredMissing]

print(f"fucntion output 1: {find(oneToHundredMissing)}")
