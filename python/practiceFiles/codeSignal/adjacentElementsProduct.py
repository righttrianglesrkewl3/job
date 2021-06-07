# 6-3-21
# kZ
"""
Given an array of integers, find the pair of adjacent elements that has the largest product and return that product.

Example

For inputArray = [3, 6, -2, -5, 7, 3], the output should be
adjacentElementsProduct(inputArray) = 21.

7 and 3 produce the largest product.

Input/Output

[execution time limit] 4 seconds (py3)

[input] array.integer inputArray

An array of integers containing at least two elements.

Guaranteed constraints:
2 ≤ inputArray.length ≤ 10,
-1000 ≤ inputArray[i] ≤ 1000.

[output] integer

The largest product of adjacent elements.

"""

inputArray = [3, 6, -2, -5, 7, 3]

def adjacentElementsProduct(inputArray):
    return max(([inputArray[i] * inputArray[i+1] for i in range(len(inputArray) - 1)]))

print(adjacentElementsProduct(inputArray))



"""
Below is a *NON-Optimal* solution that just shows a cool way to find the max key in a dictionary

def adjacentElementsProducts(inputArray):
    counts = {}
    largestProduct = None

    for i in range(len(inputArray) - 1):
        counts[(inputArray[i], inputArray[i+1])] = inputArray[i] * inputArray[i+1]

    max_key = max(counts, key=counts.get)
    largestProduct = max_key[0] * max_key[1]
    
    return largestProduct


inputArray = [3, 6, -2, -5, 7, 3]
print(adjacentElementsProducts(inputArray))

"""
