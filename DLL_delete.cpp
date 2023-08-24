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

void deleteNode(Node* &head, int pos){
    if(head == NULL){
        cout<<"Empty LL"<<endl;
        return;
    }
    Node* temp = head;
    // if single node is present
    if(head->next == NULL){
        head = NULL;
        delete temp;
        return;
    }
    // Head deletion
    if(pos == 0){
        head = head->next;
        head->prev = NULL;
        delete temp;
        return ;
    }
    // Invalid pos
    if(pos >= length(head)){
        cout<<"Invalid pos"<<endl;
        return ;
    }

    // last node
    if(pos == length(head)-1){
        Node *p = head;
        while(temp->next) temp = temp->next;
        p = temp->prev;
        p->next = NULL;
        delete temp;
        return;
    }
    // Middle node 
    else{
        Node* p = NULL;
        int i = 1;
        while(i <= pos && temp){
            p = temp;
            temp = temp->next;
            i++;
        }
        temp->next->prev = p;
        p->next = temp->next;
        delete temp;
    }
}

int main()
{
    Node* head = NULL;
    insertAtHead(head,20);
    insertAtHead(head,30);
    insertAtHead(head,40);
    insertAtHead(head,50);
    insertAtHead(head,60);
    insertAtHead(head,70);
    deleteNode(head,5);
    // deleteNode(head,2);
    // deleteNode(head,0);
    print(head);
    return 0;
}