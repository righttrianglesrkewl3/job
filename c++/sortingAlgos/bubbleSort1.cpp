// This code is practice; it is copied from programwiz.com Bubble sort page
// bubbleSort1.cpp
// kZ 3-21-21

#include <iostream>
#include <string>
#include <vector>
using namespace std;

void bubbleSort(int array[], int size) {

  // run loops two times: one for walking throught the array
  // and the other for comparison
  int outer_iter = 0;
  int inner_iter = 0;
  for (int step = 0; step < size - 1; ++step) {
      cout << "step = " << step << endl;
      outer_iter ++;
    for (int i = 0; i < size - step - 1; ++i) {
        cout << "step = " << step << " i = " << i << endl;
        inner_iter ++;
      // To sort in descending order, change > to < in this line.
      if (array[i] > array[i + 1]) {

        // swap if greater is at the rear position
        int temp = array[i];
        array[i] = array[i + 1];
        array[i + 1] = temp;
        }
    }
}
    cout << "outer iter = " << outer_iter << endl;
    cout << "inner iter = " << inner_iter << endl;
}

// function to print the array
void printArray(int array[], int size) {
  for (int i = 0; i < size; ++i) {
    cout << "  " << array[i];
  }
  cout << "\n";
}

// driver code
int main() {
  int data[] = {-2, 45, 0, 11, -9};
  int size = sizeof(data) / sizeof(data[0]);
  cout << "Sorted Array Size:\n";
  cout << size << endl;
  bubbleSort(data, size);
  cout << "Sorted Array in Ascending Order:\n";
  printArray(data, size);
}