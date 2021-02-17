#include <iostream>
using std::string;
using std::endl;
using std::cout;

class Dog {
public:
    string Name;
    int Age;

    // getter setter would need to be here if want to make attributes of class private
    // private or protected? rewatch video
    Dog(string name, int age) {
        Name = name;
        Age = age;
    }

    void Bark() {
        cout << "This dogs name is - " << Name << " - and it is " << Age << " years old" << endl;
        cout << "This dogs can bark" << endl;
        cout << "ROOOOF ROOOOOOF" << endl;
    }
};

class SARDOG: public Dog {
public:
    int ElectronicID;
    string Handler;
    
    //const.
    SARDOG(string name, int age, int electronicID, string handler)
        :Dog(name, age)
    {
        ElectronicID = electronicID;
        Handler = handler;
    }

    void Search(){
        cout << "Rescue dog " << Name << " is out on a search with handler - " << Handler << endl;
    }
};


int main()
{
    Dog regulardog1 = Dog("Betsy", 3);
    regulardog1.Bark();

    SARDOG sardog1 = SARDOG("Findy", 8, 2345, "Officer Rick");
    sardog1.Search();
}