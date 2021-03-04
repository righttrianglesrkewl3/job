#include <iostream>
using namespace std;

// single asterisk?
void print1DArray(int *arr, int size) {
    for (int i=0; i < size - 1; i++) {
        cout << arr[i] << ", ";
    }

    cout << arr[size - 1];
}

// double asterisk?
void print2dArray(int **arr, int size, int size2) {

    for (int i=0; i < size - 1; i++) {
        print1DArray(arr[i], size2);
        cout << endl;
    }

    print1DArray(arr[size - 1], size2);
    cout << endl;
}


int main()
{
    int **array; // it creates a variable to store a pointer to an int pointer.
    array = new int*[4];
    array[0] = new int[4] {1, 2, 3, 4 };
    array[1] = new int[4] {5, 6, 7, 8 };
    array[2] = new int[4] {9, 10, 11, 12 };
    array[3] = new int[4] {13, 14, 15, 16 };

    int size = 4;
    int size2 = 4;

    for (int i=0; i < size; i++) {
        // cout << *array[i] << endl;

        for (int j=0; j < size2; j++) 
            cout << array[i][j] << endl;
    }

    print2dArray(array, size, size2); //double asterisk

    print1DArray(*array, size); // single asterisk

    getchar();

}