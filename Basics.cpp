#include <iostream>
using namespace std;

// Creating a Singly Linked List-->
// 1] Using Structure-->
struct Node{
    int data;
    struct Node *next;      // Self-Referential Structure.
    
};
// 2] Using Class-->
class Node {
public:
    int data;
    Node *next; 

    Node(){                 // Default constructor
        data = 0;
        next = NULL;
    }
    
    Node(int n){            // Parameterised Constructor
        this->data = n;
        this->next = NULL;
    }
};
                   
int main()
{
    struct Node *p;         // Creating a node in stack
    p = new Node;           // Creating a node in heap
    p->data = 10;           // Accessing data
    p->next = 0;            // next pointer will became NULL.

    struct Node *p,*q;
    q = p;                  // Two pointers pointing on same node.
    q = p->next;            // Let q point on next node of p
    p = p->next;            // Let p point on next node of p
    // So the above statement has made p move on next node.
    
    // Making p as null
    struct Node *p = 0;
    struct Node *p = NULL;

    // Conditions to check if a pointer is not pointing anywhere
    if(p == NULL)
    if(p == 0)
    if(!p)
    
    // Checking last node
    if(p->next == NULL)
    if(p->next == 0)

    return 0;
}