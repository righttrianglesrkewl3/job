// Access control works on a per-class basis
// Sun 2-28-21 KZ

#include <iostream>
using namespace std;

class DateClass {
    int m_year;
    int m_month;
    int m_day;

public:
    void setDate(int year, int month, int day)
    {
        m_year = year;
        m_month = month;
        m_day = day;
    }

    void print(){
        cout << m_year << " / " << m_month << " / " << m_day << "\n" << endl;
    }

    //Note addition of this fxn
    void copyFrom(const DateClass &d)
    {
        //note that we can access the private members of d directly
        m_year = d.m_year; //couldnt usually do m.month because private (not how dot(.) used twice)
        m_month = d.m_month;
        m_day = d.m_day;
    }
};

int main()
{

    
    // DateClass date1 (2020, 06, 25); // cant do this!!!! private!!
    // date1.print();

    DateClass date1;
    date1.setDate(2020, 6, 25);
    date1.print();

    DateClass copy;
    copy.copyFrom(date1);
    copy.print();
    copy.setDate(2020, 9, 25);
    copy.print();
}