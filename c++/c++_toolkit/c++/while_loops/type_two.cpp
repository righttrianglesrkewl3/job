#include <iostream>
using namespace std;

int main() {

    // reversing number
    int number, reversedNumber=0;
    cout << "Number: ";
    cin >> number;//123

    while (number != 0){
        reversedNumber = reversedNumber * 10;
        reversedNumber += number % 10;
        number /= 10; // whatever here goes back to top of while loop and starts over
    }
    cout << "Reversed: " << reversedNumber << endl;

}