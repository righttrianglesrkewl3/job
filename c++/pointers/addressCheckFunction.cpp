//: Function that checks address of pointer and address of an array
// addressCheckFunction.cpp
// kZ 3-15-21
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

void addressCheck(int* pointerToArray, int* someArray);

int main()
{
    int intArray[] = {1,2,3,4};
    int* pintArray = intArray; // array so no reference operator (&)

    addressCheck(pintArray, intArray);

    cout << "Address of pointer that is pointing to array : \n" 
        << pintArray << endl;

    cout << "Address of array (array so no &) : \n" 
        << intArray << endl;

    cout << "Value in array initially pointed to by pointer : \n" 
        << *pintArray << endl;

    cout << "Increment address of array that the pointer is pointing to \n"     << pintArray++ << endl;

    cout << "New value pointed to by pointer: \n" << *pintArray << endl;

    // addressCheck(pintArray, intArray); 
    // cant put here because increment value in lines of code above!

}
// note that you pass array with pointer type here
void addressCheck(int* pointerToArray, int* someArray) {
    if (pointerToArray == someArray){
        cout << "[INFO] checking equality of address values...\n";
        cout << "[INFO] addresses are equal\n";
        cout << "pointerToArray argument: \n" << pointerToArray << endl;
        cout << "someArray argument: \n" << someArray << endl;
    }
    else {
        cout << "Addresses are not equal" << endl;
        cout << "pointerToArray argument: \n" << pointerToArray << endl;
        cout << "someArray argument: \n" << someArray << endl;
    }
}
