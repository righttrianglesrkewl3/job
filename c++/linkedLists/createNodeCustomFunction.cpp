// This program is practice; It creates a function that takes as an argument the 1) data for a node and 2) the link to the next node in the linked list (although this is set to default to NULL)--then returns it. The function returns a pointer to a Node so it should be assigned to a pre-initialized pointer variables in main.
// createNodeCustomFunction.cpp
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

Node* getNode(int data, Node* linkToNextNode=NULL);

int main()
{
    Node* head;
    Node* one = NULL;
    Node* two = NULL;
    Node* three = NULL;

    // allocate 3 nodes on the heap
    one = new Node();
    two = new Node();
    three = getNode(55); // my function

    // Assign value values
    one->data = 1;
    two->data = 2;
    // NOTE: dont need to assign three here because it is performed by function "getNode()" above

    // Connect nodes
    one->link = two;
    two->link = three;
    three->link = NULL;

    // assign first node to head
    head = one;

    // create pointer to point to head and print values at nodes
    Node* temp;
    temp = head;

    // big difference if put temp->data != NULL
    while (temp != NULL){
        printf("%d ", temp->data);
        temp = temp->link;
    }

    cout << "\n\nPress any key to exit program...\n";
    cin.get();

}

Node* getNode(int data, Node* linkToNextNode){
    Node* nodeVarName = new Node();
    nodeVarName->data = data;
    nodeVarName->link = linkToNextNode;

    return nodeVarName;
}
