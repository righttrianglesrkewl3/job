#include <iostream>
#include <cstdlib>
#include <string>
#include <limits>
#include <string>
#include <vector>
#include <sstream>
#include <numeric>
#include <ctime>
#include <cmath>
using namespace std;

class YouTube {
private:
    string ProtocolUsed;
    int YearCreated;
    
    static int TotalUsers;

public:
    // constructors
    YouTube();
    YouTube(string ProtocolUsed, int YearCreated);
    ~YouTube();
    void SetAll(string ProtocolUsed, int YearCreated);

    // get/set
    void SetProtocolUsed(string ProtocolUsed) {this->ProtocolUsed = ProtocolUsed;}
    string GetProtocolUsed() {return ProtocolUsed;}
    void SetYearCreated(int YearCreated) {this->YearCreated = YearCreated;}
    int GetYearCreated() {return YearCreated;}

    // get/set static int
    static int GetTotalUsers() {return TotalUsers;}

    // created to be overridden
    void ToString();
};

int YouTube::TotalUsers = 0;

// no data passed default constructor
YouTube::YouTube(){

}

// default
YouTube::YouTube(string ProtocolUsed, int YearCreated){
    this->ProtocolUsed = ProtocolUsed;
    this->YearCreated = YearCreated;
    TotalUsers ++;

}

YouTube::~YouTube(){
    cout << "This object has been destroyed! " << endl;
}

// set all
void YouTube::SetAll(string ProtocolUsed, int YearCreated){

}

// ToString()
void YouTube::ToString(){
    cout << "Protocol used = " << this->ProtocolUsed << endl;
    cout << "Created = " << this->YearCreated << endl;
    cout << "Total User Num = " << this->TotalUsers << endl;
}

// static int defined in class
// Dont do this here!
/*
// GetTotalUsers()
static int YouTube::GetTotalUsers(){

}
*/

int main()
{
    YouTube west ("TCP/IP", 2010);
    west.ToString();
}
