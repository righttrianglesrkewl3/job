// 3_14_21-Pointers.cpp 
// This file demo's initializing a pointer and then reassigning that pointer to a different variable
// kZ 3-14-21

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using std::endl;
using std::cout;

int main()
{

    int myVariable1 = 29;
    cout << myVariable1 << endl;

    int* pmyVariable1 = &myVariable1;
    *pmyVariable1 = 30;
    cout << myVariable1 << endl;

    int val2 = 400;
    cout << val2 << endl;

    pmyVariable1 = &val2;
    *pmyVariable1 = 401;
    cout << val2 << endl;

    int arr1[] = {3,4,5};
    cout << arr1 << endl;
    cout << &arr1<< endl;
    cout << *arr1 << endl;

    // cout << *(&arr1) - arr1 << endl;
    // cout << *(&arr1 + 1) - arr1 << endl;
    // cout << (arr1 + 1) - arr1 << endl;
} ///:~