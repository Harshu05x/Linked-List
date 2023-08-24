#include <iostream>
#include <unordered_map>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data = 0){
        this->data = data;
        this->next = NULL;
    }
    ~Node(){
        cout<<"Deleted Node: "<<this->data<<endl;
        this->next = NULL;
        delete next;
    }
};

void print(Node* &head){
    Node* temp = head;

    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

void removeDuplicates(Node* &head){
    if(head == NULL){
       return;
    }
    if(head->next == NULL)
        return;
    
    Node* curr = head;
    while(curr != NULL){
        // Equal
        if((curr->next != NULL) && (curr->data == curr->next->data)){       // "curr->next != NULL" this condition must be at first
                                                                            // You have to first check that curr->next is valid or not
                                                                            // then only access it's data
            Node* temp = curr->next;
            // modifiy links
            curr->next = curr->next->next;
            // delete dupilcate node
            delete temp;
        }
        // Not Equal
        else   
            curr = curr->next;      // move curr 1 step
    }
}

int main()
{
    Node* head = new Node(10); 
    Node* first = new Node(10); 
    Node* second = new Node(20); 
    Node* third = new Node(20); 
    Node* forth = new Node(30); 
    Node* fifth = new Node(40);
    Node* sixth = new Node(40);

    head->next = first;
    first->next = second;
    second->next = third;
    third->next = forth;
    forth->next = fifth;
    fifth->next = sixth;

    print(head);
    removeDuplicates(head);
    print(head);
    return 0;
}