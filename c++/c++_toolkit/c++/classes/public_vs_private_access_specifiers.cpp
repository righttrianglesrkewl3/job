#include <iostream>
using namespace std;

class DateClass {
    int m_month; // private
    int m_day; // private
    int m_year; // private

public:
    void setDate(int month, int day, int year)
    {
        m_month = month;
        m_day = day;
        m_year = year;
    }

    void print()
    {
        cout << m_month << " / " << m_day << " / " << m_year << endl;
    }

};

int main()
{
    /*
    DateClass todaysDate {10, 12, 2020};
    todaysDate.print(); 
    ====> ERROR! <======    
    */

    DateClass todaysDate;
    todaysDate.setDate(10, 12, 2020);
    todaysDate.print();
    cout << "\n" << endl;

}