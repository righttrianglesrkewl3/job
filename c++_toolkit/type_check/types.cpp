#include <iostream>
#include <typeinfo>
#include <string>

using namespace std;

int main() {
  auto x = 1;
  string my_type = typeid(x).name();
  system(("echo " + my_type + " | c++filt -t").c_str());
  return 0;
}


 // NOTE: good "real world" usage example below
// #include <iostream>
// #include <thread>
// #include <vector>
// #include <typeinfo>
// using namespace std;

// int nScreenWidth = 80;			// Console Screen Size X (columns)
// int nScreenHeight = 30;			// Console Screen Size Y (rows)
// wstring tetromino[7];
// int nFieldWidth = 12;
// int nFieldHeight = 18;
// unsigned char *pField = nullptr;

// int main()
// {
// 	// Create Screen Buffer
// 	// wchar_t *screen = new wchar_t[nScreenWidth*nScreenHeight];
// 	// for (int i = 0; i < nScreenWidth*nScreenHeight; i++) screen[i] = L' ';
// 	// HANDLE hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
// 	// SetConsoleActiveScreenBuffer(hConsole);
// 	// DWORD dwBytesWritten = 0;
//     int x;
//     int y;
//     std::string my_type;
//     std::string select_type;
    

// 	tetromino[0].append(L"..X...X...X...X."); // Tetronimos 4x4
// 	tetromino[1].append(L"..X..XX...X.....");
// 	tetromino[2].append(L".....XX..XX.....");
// 	tetromino[3].append(L"..X..XX..X......");
// 	tetromino[4].append(L".X...XX...X.....");
// 	tetromino[5].append(L".X...X...XX.....");
// 	tetromino[6].append(L"..X...X..XX.....");

// 	pField = new unsigned char[nFieldWidth*nFieldHeight]; // Create play field buffer
// 	for (int x = 0; x < nFieldWidth; x++) // Board Boundary
// 		for (int y = 0; y < nFieldHeight; y++)
//             cout << "x = " << x << " " << "y = " << y << endl;
// 			select_type = typeid(pField[y*nFieldWidth + x] = (x == 0 || x == nFieldWidth - 1 || y == nFieldHeight - 1) ? 9 : 0).name();
//             system(("echo " + select_type + " | c++filt -t").c_str()); 
// // auto x = 1;
// // string my_type = typeid(x).name();
// // system(("echo " + my_type + " | c++filt -t").c_str());
// // return 0;
// }
