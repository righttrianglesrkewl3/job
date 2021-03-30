#include <iostream>
using namespace std;
// operating on original addresses so values stored at those addresses will know
// declare above main (initialize defaults in declaration, as opposed to definition)
void getTotal(int numbers[], int size, int* total);

int main()
{
    int numbers[5] { 5,4,-2,29,6 }; 
    int total { 0 };

    getTotal(numbers, 5, &total);
    
}

// define below main (defaults would go here)
void getTotal(int numbers[], int size, int* total){

    for (int i=0; i < size; i++){
        cout << numbers[i] << '\n';
        *total += numbers[i];
    }

    cout << "Total of numbers array = " << *total << '\n';
}
