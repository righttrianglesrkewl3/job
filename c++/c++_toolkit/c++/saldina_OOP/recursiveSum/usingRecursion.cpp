// KZ 3-3-21
/* Sum numbers m-n without using recursion -- will do recursively next to show alternative to this method */

#include <iostream>
using namespace std;

int recursive_sum(int m, int n);

int main()
{

    cout << "Hey\n";
    int m { 2 };
    int n { 4 };


    cout << recursive_sum(m, n) << endl;
}

int recursive_sum(int m, int n){//m=2 //n=4
    if (m == n)
        return m;
    
    return m + recursive_sum(m + 1, n); // 
}