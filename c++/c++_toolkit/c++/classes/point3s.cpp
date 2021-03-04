#include <iostream>
using namespace std;

class Point3d {
    int m_p1, m_p2, m_p3;

public:
    void setValues(int arg1, int arg2, int arg3)
    {
        m_p1 = arg1;
        m_p2 = arg2;
        m_p3 = arg3;
    }

    void showInfo()
    {
        cout << m_p1 << m_p2 << m_p3 << "\n" << endl;
    }

    // void isEqual(const Point3d &n)
    // {
    //     if((m_p1 == n.m_p1) && (m_p2 == n.m_p2) && (m_p3 == n.m_p3))
    //         cout << "Points are equal" << endl;
    //     else
    //         cout << "Points are not equal" << endl;
    // }

    bool isEqual(const Point3d &n)
    {
        return (m_p1 == n.m_p1 && m_p2 == n.m_p2 && m_p3 == n.m_p3);
    }


};

int main()
{
    Point3d mypoint;
    mypoint.setValues(1, 2, 3);
    mypoint.showInfo();

    Point3d mypoint2;
    mypoint2.setValues(1, 3, 3);

    if (mypoint.isEqual(mypoint2))
        cout << "Points are equal" << endl;
    else
        cout << "Point are NOT equal" << endl;
}