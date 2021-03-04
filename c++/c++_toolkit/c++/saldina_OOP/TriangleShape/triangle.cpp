#include <iostream>
#include <iomanip>
using namespace std;

int main()
{

    int length;
    cout << "Length: " << endl;
    cin >> length;
    char symbol;
    cout << "Symbol: " << endl;
    cin >> symbol;

    std::system("clear");

    cout << "Drawing shape...\n" << endl;

    for (int i=1; i <= length; i++){
        for (int j=1; j <= i; j++){
            cout << setw(2) << symbol;
        }
        cout << endl;
    }

    cout << endl << endl;


    for (int i=length; i >=1; i--){
        for (int j=1; j <= i; j++){
            cout << setw(2) << symbol;
        }
        cout << endl;
    }

}