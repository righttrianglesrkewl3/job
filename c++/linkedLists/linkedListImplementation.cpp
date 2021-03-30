// This code demonstrates linked list implementation in C++
// linkedListRepresentation.cpp
// kZ 3-17-21

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// each struct node has a data item and a pointer to another struct node
struct node
{
  int data;
  struct node* link;
};

int main()
{
  // step 1:
  struct node* A; // A is a POINTER
  //A = NULL;

  // step 2:
  struct node* temp;
  temp = new node();
  temp->data = 2;
  temp->link = NULL;

  // step 3: 
  A = temp; // temp is POINTER

  cout << A->link << endl;
  cout << A->data << endl;

  cout << temp->link << endl;
  cout << temp->data << endl;

  if (A->link == temp->link)
    cout << "equal" << endl;
  else
    cout << "not equal" << endl;

  cout << "Entering while loop...\n";
  while (A != NULL) {
    printf("%d ", A->data);
    A = A->link;
  }

  cout << endl;
  cout << "EOP " << endl;
  // struct node* temp1 = A;
  // while(temp1->link != NULL){
  //   temp1 = temp1->link;
  // }

}