#include <iostream>
using namespace std;

wstring tetromino[7];

int main()
{
    cout << "Lets play tetris! " << endl;

    // create assets
    tetromino[0].append(L"....");
    tetromino[0].append(L"....");
    tetromino[0].append(L"....");
    tetromino[0].append(L"....");

    tetromino[1].append(L"....");
    tetromino[1].append(L"....");
    tetromino[1].append(L"....");
    tetromino[1].append(L"....");

    tetromino[2].append(L"....");
    tetromino[2].append(L"....");
    tetromino[2].append(L"....");
    tetromino[2].append(L"....");

    tetromino[3].append(L"....");
    tetromino[3].append(L"....");
    tetromino[3].append(L"....");
    tetromino[3].append(L"....");

    tetromino[4].append(L"....");
    tetromino[4].append(L"....");
    tetromino[4].append(L"....");
    tetromino[4].append(L"....");
    
    tetromino[5].append(L"....");
    tetromino[5].append(L"....");
    tetromino[5].append(L"....");
    tetromino[5].append(L"....");

    tetromino[6].append(L"XXXX");
    tetromino[6].append(L"XXXX");
    tetromino[6].append(L"XXXX");
    tetromino[6].append(L"XXXX");


    wcout << tetromino[0] << endl;
    wcout << tetromino[6] << endl;

    return 0;
}