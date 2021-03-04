#include <iostream>
using namespace std;

class Pilot {
public:
    string Name{};
    int Age{};

    void showInfo(){
        cout << "Name: " << Name << endl;
        cout << "Age: " << Age << endl;
    }
};

int main()
{
    Pilot pilot1 {"Joey", 20};
    pilot1.showInfo();
}