// This program shows how to pass structures as an argument to a function, and use them in your programs
// returnStructureFunctions.cpp
// kZ 3-17-21

#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

struct Person {
    char name[50];
    int age;
    float salary;
};

Person getData(Person); 
void displayData(Person); 

int main() {

    Person p;

    p = getData(p);   
    displayData(p);

    return 0;
}

// reminder: return type is person
Person getData(Person p) {

    cout << "Enter Full name: ";
    cin.get(p.name, 50);

    cout << "Enter age: ";
    cin >> p.age;

    cout << "Enter salary: ";
    cin >> p.salary;

    return p;
}

void displayData(Person p) {
    cout << "\nDisplaying Information." << endl;
    cout << "Name: " << p.name << endl;
    cout <<"Age: " << p.age << endl;
    cout << "Salary: " << p.salary;
}