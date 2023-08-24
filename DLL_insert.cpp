#include <iostream>
using namespace std;

class Node{
    public:
    Node* prev;
    int data;
    Node* next;

    Node(int data = 0){
        this->prev = NULL;
        this->data = data;
        this->next = NULL;
    }
    ~Node(){
        cout<<"Deleted: "<<this->data<<endl;
        prev = NULL;
        next = NULL;
        delete prev;
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
int length(Node* &head){
    Node* temp = head;
    int c = 0;
    while(temp){
        c++;
        temp = temp->next;
    }
    return c;
}

void insertAtHead(Node* &head, int data){
    Node* temp = new Node(data);
    if(head == NULL){
        head = temp;
        return;
    }
    temp->next = head;
    head->prev = temp;
    head = temp;
}

void insertAtEnd(Node* &head, int data){
    Node* temp = new Node(data);
    if(head == NULL){
        head = temp;
        return;
    }
    Node* p = head;
    while(p->next) p = p->next;
    p->next = temp;
    temp->prev = p;
}

void insertAtMiddle(Node* &head, int data, int pos){
    if(pos == 0){
        insertAtHead(head,data);
        return;
    }
    else if(pos >= length(head)){
        insertAtEnd(head,data);
        return;
    }

    Node* temp = new Node(data);
    if(head == NULL){
        head = temp;
        return;
    }

    int i = 1;
    Node *p = head;
    while(i < pos) {
        p = p->next;
        i++;
    }
    temp->next = p->next;
    p->next->prev = temp;
    p->next = temp;
    temp->prev = p;
}

int main()
{
    Node* head = NULL;    
    insertAtHead(head,10);
    insertAtHead(head,20);
    insertAtHead(head,30);
    insertAtHead(head,40);
    insertAtEnd(head,20);
    insertAtEnd(head,30);
    insertAtEnd(head,40);
    insertAtEnd(head,50);
    insertAtMiddle(head,1212,5);
    print(head);
    return 0;
}