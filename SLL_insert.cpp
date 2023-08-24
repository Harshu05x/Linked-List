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

void insertAtEnd(Node* &head, int data){
    // 1] Create a temp node
    Node* temp = new Node(data);
    
    // check for empty LL
    if(head == NULL){
        head = temp;
        return;
    }
    Node* p = head;
    // 2] Go to last node n insert
    while(p->next) p = p->next;
    p->next = temp;
}

void insertAtPos(Node* &head, int data, int index){
    if(index == 0){
        insertAtHead(head,data);
        return;
    }
    // 1] Create a temp node
    Node* temp = new Node(data);
    
    // check for empty LL
    if(head == NULL){
        head = temp;
        return;
    }

    Node* p = head;
    int i = 1;
    while(i < index && p->next){
        p = p->next;
        i++;
    }
    temp->next = p->next;
    p->next = temp;
}

void print(Node* &head){
    Node* temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main()
{
    Node* head = NULL;
    insertAtHead(head,60);
    insertAtHead(head,50);
    insertAtHead(head,40);
    insertAtHead(head,30);
    insertAtHead(head,20);
    insertAtHead(head,10);
    insertAtEnd(head,70);
    insertAtEnd(head,80);
    insertAtEnd(head,90);
    insertAtEnd(head,100);
    insertAtEnd(head,110);
    insertAtEnd(head,120);
    insertAtPos(head,71,0);
    insertAtPos(head,72,1);
    insertAtPos(head,73,9);
    insertAtPos(head,74,10);
    insertAtPos(head,75,11);
    insertAtPos(head,76,12);
    insertAtPos(head,77,13);
    insertAtPos(head,78,14);
    insertAtPos(head,79,114);

    print(head);
    return 0;
}