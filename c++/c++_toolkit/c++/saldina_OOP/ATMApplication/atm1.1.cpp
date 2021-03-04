// KZ 3-3-21
// Build OOP App

#include <iostream>
using namespace std;

class Bank {
public:
    string m_Greeting { "Welcome to Kevins Bank" };
    int m_YearsOpen { 20 };

    void greetCustomer(){
        cout << m_Greeting << endl;
        cout << "Serving you for " << m_YearsOpen << " years! \n";
    }
};

class Customer : public Bank {
private:
    string m_Name;
    float m_Balance = 0;

public:
    void setInfo (string sName, float fBalance){
        m_Name = sName;
        m_Balance = fBalance;
    }

    void showInfo(){
        cout << "Name: " << m_Name << endl;
        cout << "Balance: " << m_Balance << endl;
    }

};

int main()
{
    Customer c1;
    c1.greetCustomer();
    c1.showInfo();
    c1.setInfo("Kevin", 1000.0);
    c1.showInfo();
}