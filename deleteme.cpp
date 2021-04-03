// 3-29-21
// kZ
#include <iostream>
#include <vector>
#include <string>
using namespace std;


bool isValidSubsequence(vector<int> array, vector<int> sequence) {
  // Write your code here.
    if (sequence.size() > array.size())
    return false;

    int findIdx = 0;
    int total = sequence.size();
    for (int i = 0; i < array.size(); i++){
        int arrayVal = array[i];
        for (int j = findIdx; j < sequence.size(); j++){
            int sequenceVal  = sequence[findIdx];
            if (arrayVal == sequenceVal){
                cout << arrayVal << " " << sequenceVal << endl;
                findIdx++;
                break;
            }
        }
    }
    if (findIdx == total){
        return true;
    } else {
        return false;
    }

}
int main()
{
    vector<int> array = {5, 1, 22, 25, 6, -1, 8, 10};
    vector<int> sequence = {1, 6, -1, -1};

    bool checkBool = isValidSubsequence(array, sequence);
}
