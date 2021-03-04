#include <iostream>
using namespace std;

// define function above name and dont forget to pass arguments
void introduceMe(string name, int age=0); // hard-coded initialized in declaration

int main()
{
    introduceMe("Kevin", 30);
    introduceMe("Bestie");
}

// define function below main
void introduceMe(string name, int age){
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
}