// stack heap (learn cpp chap 11.3)

#include <iostream>
#include <string>
using namespace std;

class Stack {
private:
    int m_arr[10] {1, 1, 1, 0, 0, 0, 0, 0, 0 ,0};
    int m_stackSize=0;

public:
    void reset()
    {
        for (int i=0; i < 10; i++)
            m_arr[i] = 0;
    }

    bool push()
    {

    }

    int pop()
    {

    } 

    void print()
    {
        
    }

    void printArray()
    {
        for (int i=0; i < 10; i++)
            cout << m_arr[i] << endl;
    }

    void setValueByIndex(int idx, int val)
    {
        m_arr[idx] = val;
    }


};




int main()
{
    Stack st1;
    st1.printArray();
    st1.setValueByIndex(0, 200);
    st1.reset();
    cout << "[INFO] reset array to 0 at all positions" << endl;
    st1.printArray();

    return 0;
}