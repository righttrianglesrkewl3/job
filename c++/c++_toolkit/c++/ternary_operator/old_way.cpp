#include <iostream>
using namespace std;

int main()
{
    int a, b;

    cout << "Enter a " << endl;
    cin >> a;

    std::system("clear");

    cout << "Enter b " << endl;
    cin >> b;

    if (a < b)
        cout << "a is less than b " << endl;

    else if (a > b)
        cout << "a is greater than b " << endl;

    else
        cout << "a and b are equal " << endl;

    cout << a << endl;
    cout << b << endl;
}