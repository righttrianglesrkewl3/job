#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int number;
    cout << "Number: ";
    cin >> number;

    if (number == 0)
        cout << "You have entered 0. \n";
    else {
        if (number < 0)
            number *= -1; // or number = -1 * number;
        //1325
        //counter=0
        int counter=0;
        while (number > 0) {
            number /= 10; //takes away last digit (aka number = number / 10)
            counter++;
        }
        cout << "counter = " << counter << endl;

    }

}