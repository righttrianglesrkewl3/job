#include <iostream>
#include <vector>
#include <tuple>
#include <string>
#include <map>
using namespace std;

int main()
{
// add hash table/dict to store team score


    typedef tuple <string, string> matchup;
    typedef tuple <string, int> outcome;

    vector<int> results = { 0, 0, 1 };

    vector <matchup> competitions;
    vector <outcome> outcomeVec;

    // Add some test data
    outcomeVec.push_back(make_tuple("C#", 0));
    outcomeVec.push_back(make_tuple("HTML", 0));
    outcomeVec.push_back(make_tuple("Python", 0));

    // Add some test data
    competitions.push_back(make_tuple("HTML", "C#"));
    competitions.push_back(make_tuple("C#", "Python"));
    competitions.push_back(make_tuple("Python", "HTML"));
    
    // Result:
    for (int i = 0; i < competitions.size(); i++)
    {
        cout << get<1>(competitions[i]) << " " << endl;
    }

        // Result:
    for (int i = 0; i < results.size(); i++)
    {
        cout << results[i] << " " << endl;
    }



    for (int i = 0; i < results.size(); i++){
        if (results[i] == 0){
            string tmp = get<1>(competitions[i]);

            cout << "winner (" << results[i] << ")" << " --> AWAY " << tmp << endl;
            for (int k = 0; k < outcomeVec.size(); k++){
                if (tmp == get<0>(outcomeVec[k])){
                    cout << "tmp = " << tmp << endl;
                    get<1>(outcomeVec[k]) += 3;
                }
            }
        }
        else if (results[i] == 1){
            string tmp2 = get<0>(competitions[i]);

            cout << "winner (" << results[i] << ")" << " --> HOME " << tmp2 << endl;   
            for (int k = 0; k < outcomeVec.size(); k++){
                if (tmp2 == get<0>(outcomeVec[k])){
                    cout << "tmp = " << tmp2 << endl;
                    get<1>(outcomeVec[k]) += 3;
                }
            }
        }

    }

    cout << "Final outcome....\n";
    int max = 0;
    string winner;
    for (int i = 0; i < outcomeVec.size(); i++){
        if (get<1>(outcomeVec[i]) > max){
            max = get<1>(outcomeVec[i]);
            winner = get<0>(outcomeVec[i]);
        }
        cout << get<0>(outcomeVec[i]) << endl;
        cout << get<1>(outcomeVec[i]) << endl;
    } 
    cout << "Winner = " << winner << endl;
    cout << endl;
}
