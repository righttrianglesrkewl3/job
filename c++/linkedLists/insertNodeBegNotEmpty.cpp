// This program is practice; it demonstrates how to insert a node at the end of a *NONEMPTY linked list. When the list is empty, there is a slightly different implementation to use so be aware of this.
// insertNodeBegNotEmpty.cpp
// kZ 3-22-21
#include <iostream>
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
    
    Node* node1;
    node1 = new Node();
    node1->data = 10;
    node1->link = NULL;

    Node* node2;
    node2 = new Node();
    node2->data = 30; 
    node2->link = NULL;

    // link nodes
    head = node1;
    node1->link = node2;

    // create temp node
    Node* temp;
    temp = head;

    // loop through and display each element in linked list
    while(temp != NULL) {
        printf(" %d -->", temp->data);
        temp = temp->link; // this is an address!
        //cout << temp << endl; ADDRESS!
    }


    // create node to be inserted at end
    Node* insertBeginningNode;
    insertBeginningNode = new Node();
    insertBeginningNode->data = 77;
    insertBeginningNode->link = NULL;

    // address that head WAS pointing to gets assigned to the
        // link field of the node that is being inserted at 
            // beginning
    insertBeginningNode->link = head;
    head = insertBeginningNode;
    

    cout << endl;
    return 0;
}
