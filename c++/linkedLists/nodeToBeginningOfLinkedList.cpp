// This program is practice; it is the implmentation of FreeCodeCamp DS video I have been learning data structures from. This program will demo how to insert a node to the beginning of a linked list
// kZ 3-21-21
// nodeToBeginningOfLinkedList.cpp

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* link;
};


int main()
{
    // initialize nodes
    Node* head;

    Node* node1;
    node1 = new Node();
    node1-> data = 23;
    node1->link = NULL;

    Node* node2;
    node2 = new Node();
    node2->data = 30;
    node2->link = NULL;

    // link nodes
    head = node1;
    node1->link = node2;

    // initialize node to add to end of linked list after traversal
    Node* end;
    end = new Node();
    end->data = 100;
    end->link = NULL;

    // initialize temp node
    Node* temp;
    temp = head;

    // traverse through nodes
    while(temp->link != NULL){
        //printf(" %d -->", temp->data);
        temp = temp->link;
    }
    // assign end node to temp pointer that caused while loop to end
    temp->link = end;

    // traverse through nodes again and print values
    // ***(temp2 != as opposed to temp2->link this time)***
    Node* temp2;
    temp2 = head;
    while(temp2 != NULL){
        printf(" %d --> ", temp2->data);
        temp2 = temp2->link;
    }

    cout << endl;
    return 0;
}