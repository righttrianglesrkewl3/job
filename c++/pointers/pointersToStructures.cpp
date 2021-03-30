// C++ Pointers to Structures
// pointersToStructures.cpp
// kZ 3-17-21

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// dot and arrow operator are used to reference individual members of classes, structures, and unions.

struct Person {
    int height;
    float weight;
};

struct Distance {
    int feet;
    int inch;
};

void changeHeightByReference(Person& somePersonStruct);

int main()
{
    struct Person tom;
    Person *personPtr = &tom;

    tom.height = 120;
    tom.weight = 200;
    cout << tom.height << endl; // dot operator for actual object
    cout << personPtr->weight << endl; // arrow for pointer to object

    cout << "Toms height: \n" << tom.height << endl;

    Distance *distancePointer, dist1;
    distancePointer = &dist1;

    cout << "Enter feet: " << endl;
    cin >> dist1.feet; // dot for object 
    cout << dist1.feet << endl;
    cout << "Enter inches: " << endl;
    cin >> distancePointer->inch; // arrow for pointer to struct
    cout << distancePointer->inch << endl;

    changeHeightByReference(tom);
    cout << "Toms height: \n" << tom.height << endl; 

    return 0;
}

void changeHeightByReference(Person& somePersonStruct) {
    somePersonStruct.height = 500;
}