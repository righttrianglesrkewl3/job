def sortedSquaredArray(array):
    # Write your code here.
	array = [array[i] * array[i] for i in range(len(array))]
    return sorted(array)
