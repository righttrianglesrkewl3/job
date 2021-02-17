// basic hangman program
#include <iostream>
#include <string>
using namespace std;

int main()
{
    unsigned maxguess(0);
// 1. Create a string variable for the secret word
    string hidden("concealed");
// 2. Create a string variable for the answer
    string answer("*********");
// 3. Create a char variable for the letter the user will guess
    char guess;
// 4. Ask the user to enter a letter
/*  * * * * * I'll ask later within the loop * * * * *
**  cout << "Type a letter and hit Return or Enter at will... ";
**  cin >> guess;
*/
// 5. Place this in a loop so the user can enter another letter
    do
    {
        cout << "Uncovered: >>" << answer << "<< Your guess pls: "; /* alas same propmt also for run-in cycle */
        cin >> guess;
// 6. Use Replace command to replace correct letter guessed with letters of secret word.
/* do not know replace() */
        // for(int i = 0; i < hidden.length(); i++)
        for(auto i = 0; i < static_cast<int>(hidden.size()); ++i)
        {
            if (guess == hidden[i])
                answer[i] = guess;
        }
// 7. Stop the program and “hang” the user after 7 incorrect guesses or win
    } while (++maxguess < 7);
    cout << "Game over: >>" << answer << "<<";
}
