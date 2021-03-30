// KZ 3-3-21
/* Sum numbers m-n without using recursion -- will do recursively next to show alternative to this method */

#include <iostream>
using namespace std;

int main()
{

    cout << "Hello \n";

    // Sum numbers between m-n
    int m { 2 };
    int n { 4 };
    int sum { 0 };

    for (int i=m; m <= n; m++){
        cout << m << '\n';
        sum += m;
        cout << "Sum in this iteration = " << sum << '\n';
    }
    cout << "Total sum = " << sum << '\n';

}
