// This program is practice; it uses the programwiz.com Linked List Operations page to insert elements to a linked node either at.. 1)beginning 2) middle 3) end of the linked list.
// linkedListOperations.cpp
// kZ 3-20-21

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* link;
};

int main(){
    // initialize nodes
    Node* head;
    Node* node1;
    node1 = new Node();
    node1->data = 1;
    node1->link = NULL;

    Node* node2;
    node2 = new Node();
    node2->data = 25;
    node2->link = NULL;

    Node* node3;
    node3 = new Node();
    node3->data = 9;
    node3->link = NULL;

    // connect nodes
    head = node1;
    node1->link = node2;
    node2->link = node3;

        // ?? see above
    Node* temp0;
    temp0 = head;
    // WARNING (understand this)!

    cout << "Original linked list \n";
    while(temp0 != NULL){
        printf("%d -->", temp0->data);
        temp0 = temp0->link;
    }

    /*
    // ?? see below
    Node* temp;
    temp = head;
    // WARNING (understand this)!
    */

    // cout << "link value pointed to by head (aka link address stored in node1's link field) \n" << head->link << endl;
    // cout << "address of pointer node2 \n" << node2 << endl;
    // cout << "head->link->link (aka Node2 link) \n" << head->link->link << endl;
    // cout << "head->link->data (aka Node2 data) \n" << head->link->data << endl;

    // inform user where program currently is
    cout << "\n\nInserting at beginning\n";

    // initialize new node to put at beginning
    Node* insertBeginningNode;
    insertBeginningNode = new Node();
    insertBeginningNode->data = 77;
    insertBeginningNode->link = NULL;

    // address that head WAS pointing to gets assigned to the
        // link field of the node that is being inserted at 
            // beginning
    insertBeginningNode->link = head;
    head = insertBeginningNode;
    
    // ?? see above
    Node* temp;
    temp = head;
    // WARNING (understand this)!

    while(temp != NULL){
        printf("%d -->", temp->data);
        temp = temp->link;
    }

    temp = head; // must do this or segmentation fault!
    cout << "\n\n\ntemp data \n" << temp->data;
    cout << "\n\nentering loop2\n";
    while(temp->link != NULL){
        printf("%d -->", temp->data);
        temp = temp->link;
    }

    cout << endl;
    return 0;

}