// This code demonstrates linked list implementation in C++ (re-do from yesterday for practice)
// RWlinkedListImplementation.cpp
// kZ 3-18-21

#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct node {
    int data;
    struct node* link;
};

int main()
{
    // initialize head node
    struct node* head; // head is a POINTER


    // create another node
    struct node* newNode1; // newNode1 is a POINTER
    newNode1 = new node();
    newNode1->data = 5;
    newNode1->link = NULL;

    cout << head << endl;
    cout << &head << endl;
    cout << newNode1 << endl;
    cout << &newNode1 << endl;


    cout << "assign " << endl;
    head = newNode1;
    cout << head << endl;
    cout << head->data << endl;

    cin.get(); // waits for keypress?

}