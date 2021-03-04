// make turns a bunch of c++ files into binary
#include <iostream>
using namespace std;

// int main()
// {
//     int hostUserNum, guestUserNum;
//     cout << "Host: ";
//     cin >> hostUserNum;
//     std::system("clear");
//     cout << "Guest: ";
//     cin >> guestUserNum;

//     if (hostUserNum == guestUserNum)
//         cout << "Correct!" << endl;

//     else
//     cout << "Failed!" << endl;
// }

int main()
{
    int hostUserNum, guestUserNum;
    char* gameTitle = "Lets play a game!";

    cout << gameTitle << endl;

    cout << "Host: ";
    cin >> hostUserNum;

    std::system("clear");

    cout << "Guest: ";
    cin >> guestUserNum;

    if (hostUserNum == guestUserNum)
        cout << "You win!";
    else 
        cout << "You failed!";
}