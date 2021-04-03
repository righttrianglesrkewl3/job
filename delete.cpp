#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
using namespace std;

vector<int> sortedSquaredArray(vector<int>& arrayToSortRef){
  // run loops two times: one for walking throught the array
  // and the other for comparison
    int size = arrayToSortRef.size();
    vector<int> outputVector = {};

    for (int i = 0; i < arrayToSortRef.size(); i++){
        int tmpVal = arrayToSortRef[i] * arrayToSortRef[i];
        cout << "Value = " << arrayToSortRef[i] << endl;
        cout << "Value Squared = " << (arrayToSortRef[i] * arrayToSortRef[i]) << endl;
        outputVector.push_back(tmpVal);
    }
    for (int step = 0; step < size - 1; ++step) {
        for (int i = 0; i < size - step - 1; ++i) {

            // To sort in descending order, change > to < in this line.
            if (outputVector[i] > outputVector[i + 1]) {

            // swap if greater is at the rear position
            int temp = outputVector[i];
            outputVector[i] = outputVector[i + 1];
            outputVector[i + 1] = temp;
            }
        }
    }

    return outputVector;
}

vector<int> oldArray = {3, 2, 1};

vector<int> newArray = sortedSquaredArray(oldArray);
