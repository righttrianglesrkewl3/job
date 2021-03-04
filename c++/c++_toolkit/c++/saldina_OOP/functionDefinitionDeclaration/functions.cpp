#include <iostream>
using namespace std;

void sayHello(); // this is a declaration. Press F12 to go to function definition

int main()
{
    cout << "You are at main() " << endl;
    sayHello();
    sayHello();
    cout << endl << endl;

    return 0;
}

void sayHello(){
    cout << "Hello there! (from sayHello()) \n";
}