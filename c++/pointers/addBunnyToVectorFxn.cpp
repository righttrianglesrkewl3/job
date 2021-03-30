// Create function to add an object to a vector by passing a reference to the object and vector to a function as arguments
// addBunnyToVectorFxn.cpp
// kZ 3-16-21

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

class Bunny {
public:
    string Name;
    int Age;
public:
    Bunny(string name, int age)
    {
        Name = name;
        Age = age;
    }
    ~Bunny() {cout << "Destroyed " << Name << "\n";}

    void toString(){
        cout << "Name: \n" << Name << endl;
        cout << "Age: \n" << Age << endl;
    }

};

void addToVector(vector<Bunny>& someVector, Bunny& someBunny);

int main()
{
    Bunny bunny1 ("Bae", 20);
    bunny1.toString();

    vector<Bunny> bunnyVector;
    cout << "Len of bunnyVector: \n" 
        << bunnyVector.size() << endl;

    bunnyVector.push_back(bunny1);
    cout << "Len of bunnyVector after fxn call: \n" 
        << bunnyVector.size() << endl;

    cout << "Show first element of vector: \n";
    cout << bunnyVector[0].Name << endl;

    cout << endl;
    cout << "End of program.\n";
    return 0;
}

void addToVector(vector<Bunny>& someVector, Bunny& someBunny){
    someVector.push_back(someBunny);
}