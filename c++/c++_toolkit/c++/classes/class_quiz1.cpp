#include <iostream>
using namespace std;

class IntPair {
private:
    int m_variable1{};
    int m_variable2{};

public:

    void set(int arg1, int arg2){
        m_variable1 = arg1;
        m_variable2 = arg2;
    }

    void print(){
        cout << "Pair = " << m_variable1 << " , " << m_variable2 << endl;

    }
};



int main()
{
    IntPair p1;
    p1.set(1,1);
    p1.print();

    IntPair p2;
    p2.set(3,4);
    p2.print();

    return 0;
}