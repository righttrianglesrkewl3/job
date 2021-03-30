// This program is more practice for implementing linked lists in C++
// RW2linkedListImplementation.cpp
// kZ 3-20-21

#include <iostream>
#include <cmath>
#include <vector>
#include <string>
using namespace std;

class Node {
public:
    int data;
    Node* link;
};

int main()
{
    Node* head;

    Node* newNode1;
    newNode1 = new Node();
    newNode1 -> data = 5;
    newNode1 -> link = NULL;

    Node* newNode2;
    newNode2 = new Node();
    newNode2->data = 20;
    newNode2->link = NULL;

    // link nodes
    head = newNode1;
    newNode1->link = newNode2;

    // create node to be inserted at the end of LL (non-empty)
    Node* endNode;
    endNode = new Node();
    endNode->data = 29;
    endNode->link = NULL;

    // loop through until second to last node
    Node* temp;
    temp = head;
    while (temp->link != NULL){
        temp = temp->link;
    }
    // since inserting at end... just need to point node before to this node
    temp->link = endNode;

    // create temp pointer to node to iterate and print each element
    Node* tempIter;
    tempIter = new Node();
    tempIter = head; // need this!
    while(tempIter != NULL) {
        printf(" %d -->", tempIter->data);
        tempIter = tempIter->link;
    }

    cout << endl;
    return 0;


}