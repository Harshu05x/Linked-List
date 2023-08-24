#include <iostream>
using namespace std;

#include <iostream>
using namespace std;

class Node{
    public:
    int val;
    Node* next;
    Node(int data = 0){
        this->val = data;
        this->next = NULL;
    }
    ~Node(){
        cout<<"Deleted: "<<this->val<<endl;
        this->next = NULL;
        delete next;
    }
};

void print(Node* &head){
    Node* temp = head;

    while(temp){
        cout<<temp->val<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
int length(Node* &head){
    Node* temp = head;
    int len = 0;
    while(temp){
        len++;
        temp = temp->next;
    }
    return len;
}

Node* rotateLL(Node* head,int k){
    if(head == NULL) return NULL;

    int len = length(head);
    if(k % len == 0) return head;

    int newK = len - (k % len) - 1;

    Node* temp = head;
    while(newK--){
        temp = temp->next;
    }

    Node* newHead = temp->next;
    Node* p = newHead;
    temp->next = NULL;
    while (p->next)
        p = p->next;
    p->next = head;
    return newHead;
} 

int main()
{
    Node* head = new Node(1); 
    Node* sec = new Node(2); 
    Node* third = new Node(3); 
    Node* forth = new Node(4);
    Node* fifth = new Node(5);
    Node* sixth = new Node(6);
    Node* seventh = new Node(7);
    Node* eighth = new Node(8);
    Node* ninth = new Node(9);
    Node* tenth = new Node(10);

    head->next = sec;
    sec->next = third;
    third->next = forth;
    forth->next = fifth;
    fifth->next = sixth;
    sixth->next = seventh;
    seventh->next = eighth;
    eighth->next = ninth;
    ninth->next = tenth;
    tenth->next = NULL;

    
    int k = 6;
    print(head);
    Node* ans = rotateLL(head,6);
    print(ans);
     
    return 0;
}