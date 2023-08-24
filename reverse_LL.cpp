#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data = 0){
        this->data = data;
        this->next = NULL;
    }
};

void insertAtHead(Node* &head, int data){
    // 1] Create a temp node
    Node* temp = new Node(data);

    // 2] attach temp n head node by
    temp->next = head;

    // 3] bring head at starting
    head = temp;
}

void print(Node* &head){
    Node* temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

// using iteratiom
Node* reverseLL(Node* &head){
    if(head == NULL){
        cout<<"Empty LL"<<endl;
        return;
    }

    Node* p = NULL, *q = head, *r = NULL;
    while(q){
        p = q->next;
        q->next = r;
        r = q;
        q = p;
    }
    return r;
}

// using recursion
Node* reverseLL(Node* prev, Node* curr){
    if(curr == NULL)
        return prev;
    Node* next = curr->next;
    curr->next = prev;
    return reverseLL(curr,next);
}

int main(){
    Node* head = new Node(90);
    insertAtHead(head,80);
    insertAtHead(head,70);
    insertAtHead(head,60);
    insertAtHead(head,50);
    Node* curr = head, *prev = NULL;

    head = reverseLL(prev,curr);
    print(head);
    return 0;
}