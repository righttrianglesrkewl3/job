// Ternary Operator (conditional operator)
// KZ
// 2-25-21

/*
Ternary Operator Signature
Condition ? Expression1 : Expression2;
When to use? Hence,
 it's better to only use ternary operator to replace simple if else statements.
*/
// char (i.e. bytes)

#include <iostream>
using namespace std;


int main()
{
    int hostUserNum, guestUserNum;

    const char* gameTitle = "Lets play a game!";
    cout << "Lets play a game!";

    std::system("clear");

    cout << "Host: ";
    cin >> hostUserNum;

    std::system("clear");

    cout << "Guest: ";
    cin >> guestUserNum;

    (hostUserNum == guestUserNum)? cout << "Correct!" : cout << "Failed!";

    (gameTitle == "Lets play a game!")? cout << "Same string!": cout << "Different string!";

/*
    Ternary operator replaces if/else (below replaced with ternary operator)
    if(hostUserNum == guestUserNum)
        cout << "You win!";
    else
        cout << "You lose!";
*/

}