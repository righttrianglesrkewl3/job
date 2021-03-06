// inspired by tutorial: 
// http://www.newthinktank.com/2018/04/c-tutorial-10-2 && /
// https://www.youtube.com/watch?v=ZOKLjJF54Xc
// KZ 3-4-21

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
using namespace std;

class Animal {
private:
    std::string name;
    double height;
    double weight;

    // static variables share same value for all objects of Animal class
    static int numOfAnimals;

public:
    // A constructor is called each time an object is created
    Animal(std::string name, double height, double weight);

    // Create an overloaded constructor for when no data is passed
    Animal(); // why not define constructor inside class?

    // You can declare function prototypes (NOTE: only types passed not variable name)
    void SetAll(std::string, double, double);

    // get/set "Name"
    std::string GetName() {return name;}
    void SetName(std::string name) {this->name = name;}

    // get/set "Height"
    double GetHeight() {return height;}
    void SetHeight(double height) {this->height = height;}

    // get/set "Weight"
    double GetWeight() {return weight;}
    void SetWeight(double weight) {this->weight = weight;}

    // Static methods can only access static fields
    static int GetNumOfAnimals() {return numOfAnimals;}
    
    void DebugClassAttributes(){
        cout << "Name = " << name << '\n';
        cout << "Height = " << height << '\n';
        cout << "Weight = " << weight << '\n';
        cout << "Num of animals = " << numOfAnimals << '\n';
    }

};

// Refer to class fields and methods with ::
int Animal::numOfAnimals = 0;

// Define prototype method
void Animal::SetAll(std::string name, double height, double weight){
    this->name = name;
    this->height = height;
    this->weight = weight;
    // Animal::numOfAnimals++;
}

// why am I doing this outside class?
// Define the constructor
Animal::Animal(std::string name, double height, double weight){
    this->name = name;
    this->height = height;
    this->weight = weight;
    Animal::numOfAnimals++;
}
Animal::Animal(){
    this->name = "";
    this->weight = 0;
    this->height = 0;
    Animal::numOfAnimals++;
}

int main()
{
    Animal ani1;
    ani1.SetName("Betty");
    ani1.SetHeight(20);
    ani1.SetWeight(100);
    ani1.DebugClassAttributes();

    Animal ani2("Alice", 30, 300);
    // ani2.SetName("Alice");
    // ani2.SetHeight(30);
    // ani2.SetWeight(300);
    ani2.DebugClassAttributes();

    Animal ani3;
    ani3.SetAll("Tim", 40, 400);
    // ani3.SetName("Tim");
    // ani3.SetHeight(40);
    // ani3.SetWeight(400);
    ani3.DebugClassAttributes();
}
