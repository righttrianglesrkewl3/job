//: Function to accept arrays and double them
// doubleArraywPointersFxn.cpp
// kZ 3-15-21
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

void doubleArray (int *arr, int size);

int main()
{
    int intArray[] = {1,2,3,4};
    int* pintArray = intArray;

    doubleArray(intArray, 4);

    // see if values changed in intArray or if "ceased to exist" in function
    cout << "Values of array after being doubled: \n";
    for (int i=0; i < 4; i++){
        cout << intArray[i] << endl;
    }

}

void doubleArray (int *arr, int size){
    // 1: pointer to array 2: size of array
    // wont change in main if dont assign inside fxn
    for (int i=0; i < size; i++){
        arr[i] = arr[i] * 2;
    }
}