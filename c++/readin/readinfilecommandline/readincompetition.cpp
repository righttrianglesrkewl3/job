// find all lines with numbers...
// add numbers on each line...
// "namespace collision"
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std; // would never actually use this in production code like CodyBEauty
//basically enumerating lines as we go through them


//argument vector is array of C style strings
// 0 based strings in C++ so zero-th position is the name of the code file
// aka main.cpp and the next argument aka position 1 will be the name of the input file
int main(int argc, char const *argv[]) {
    ifstream f(argv[1]);
    string line;
    
    while(getline(f, line)) {
        std::cout << line << std::endl;
    }

    return 0;
}