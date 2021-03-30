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

void addByRef(int &num1, int &num2);

void wrongSwap(int num1, int num2); // WRONG (wont swap)

void storeOutputToA(int num1, int num2, int output);

void passCopyBad(int outputPlaceholder);

void passRefGood(int &outputPlaceholder);

int main()
{
    // initialize variables
    int a = 1;
    int b = 2;
    int output = 0;

    cout << "Before swap: " << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    wrongSwap(a, b); // WRONG (wont swap)

    cout << "After **WRONG** swap: " << endl;
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
    addByRef(a, b);

    // call storeOutputToA() fxn
    cout << "Result of storeOutputToA() fxn: " << endl;
    storeOutputToA(a, b, output);

    // call passCopy
    passCopyBad(a);
    cout << a << endl;

    passRefGood(a);
    cout << a << endl;

    cout << "Program finished..." << endl;

    return 0;

}

void swap(int &num1, int &num2){
    int temp;
    temp = num1;
    num1 = num2;
    num2 = temp;
}

void wrongSwap(int num1, int num2){
    int temp;
    temp = num1;
    num1 = num2;
    num2 = temp;
}

int add(int num1, int num2){ // pass by value (value aka 5)
    return num1 + num2;
}

void addByRef(int &num1, int &num2){ // pass by reference (address aka 0x6ff)
    int output;
    output = num1 + num2;
    cout << "Output = " <<  output << endl;
}

void storeOutputToA(int num1, int num2, int output){
    output = num1 + num2;
    cout << output << " , " << num1 << endl;
}

void passCopyBad(int outputPlaceholder){ 
    outputPlaceholder = 29; 
} 

void passRefGood(int &outputPlaceholder){ 
    outputPlaceholder = 29; 
} 

