#include <iostream>
#include <cstdlib>
#include <string>
#include <limits>
#include <string>
#include <vector>
#include <sstream>
#include <numeric>
#include <ctime>
#include <cmath>
using namespace std;

void swap(int &num1, int &num2);

int add(int num1, int num2);

int addByRef(int &num1, int &num2);

int main()
{
    // initialize variables
    int a = 1;
    int b = 2;

    cout << "Before swap: " << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    
    // call swap() fxn
    swap(a, b);

    cout << "After swap: " << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    // call add() fxn
    int resultOfAddition;
    resultOfAddition = add(a, b);
    cout << "After Addition (call copy): " << endl;
    cout << "Result of addition of " << a << " + " << b << " = " << resultOfAddition << endl;

    // call addByRef() fxn
    int resultOfAddRef;
    resultOfAddRef = addByRef(a, b);
    cout << "After Addition (call ref): " << endl;
    cout << "Result of addition of " << a << " + " << b << " = " << resultOfAddRef << endl;

    cout << "Program finished..." << endl;

    return 0;

}

void swap(int &num1, int &num2){
    int temp;
    temp = num1;
    num1 = num2;
    num2 = temp;
}

int add(int num1, int num2){ // pass by value (value aka 5)
    return num1 + num2;
}

int addByRef(int &num1, int &num2){ // pass by reference (address aka 0x6ff)
    return num1 + num2;
}
