#include <vector>
using namespace std;

vector<int> twoNumberSum(vector<int> array, int targetSum) {
  // Write your code here.
	  int arraySize = array.size();

    int tempSum = 0;
    bool match = false;
    vector<int> output = {};

    for (int i = 0; i < arraySize; ++i){
        if (match == true)
            break;
        for (int j = 1; j < arraySize; ++j){
            tempSum = array[i] + array[j];
            if ( (tempSum == targetSum ) && (array[i] != array[j]) ){
                output.push_back(array[i]);
                output.push_back(array[j]);
                match = true;
            }
        }
    }
		return output;
}

