#include <iostream>
using namespace std;

int main()
{
    /*
    int a, b=5; //NO!
    */

   int a, b(5); // direct initializtion
   int c, d{10}; // list initialization
   int f = 500, e = 600; // copy assignment

    cout << a << b << endl;
    cout << c << d << endl;
    cout << e << f << endl;

}