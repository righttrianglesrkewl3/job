// This program is practice; it initializes a pointer to a node which is called head. Initially, the head pointer doesn't point to anything because the list starts off empty. The program then dynamically allocates memory for a new node and then points the head node to this new node just created.
// fxnAddNodeToEmptyLinkedList.cpp
// kZ 3-21-21

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* link;
};

void pointHeadToNode1(Node** headRef, Node** newNodeRef);

void pointHeadToNode2(Node*& headRef, Node*& newNodeRef);

int main()
{
    // initialize head node
    Node* head;

    // initialize a new node
    Node* node1;
    node1 = new Node();
    node1->data = 55;
    node1->link = NULL;

    // point head to newly created node
    //head = node1;
    //pointHeadToNode1(&head, &node1);
    pointHeadToNode2(head, node1);

    cout << "head->data = \n" << head->data << endl;

    cout << endl;
    return 0;

}

void pointHeadToNode1(Node** headRef, Node** newNodeRef){
    *headRef = *newNodeRef;
}

void pointHeadToNode2(Node*& headRef, Node*& newNodeRef){
    headRef = newNodeRef;
}
