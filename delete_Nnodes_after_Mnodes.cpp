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

void delete_Nnodes_after_Mnodes(Node* &head, int m, int n){
    if(head == 0) return;

    Node* it = head;
    for(int i = 0; i < m-1; i++){
        if(!it) return;
        it = it->next;
    }

    if(!it) return;
    
    Node* mthNode = it;
    it = mthNode->next;
    for(int i = 0; i < n; i++){
        if(!it) break;
        Node* temp = it->next;
        delete it;
        it = temp;
    }
    mthNode->next = it;

    delete_Nnodes_after_Mnodes(it,m,n);
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
    delete_Nnodes_after_Mnodes(head,2,2);
    print(head); 
    return 0;
}