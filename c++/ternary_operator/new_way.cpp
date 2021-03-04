#include <iostream>
using namespace std;

int main()
{
    int a = 2, b = 3;
    std::string result;

    cout << a << endl;
    cout << b << endl;

    result = a > b ? "a is greater than b " : a == b ? "a is equal to b" : "a is less than b ";
    cout << result << endl; 
}