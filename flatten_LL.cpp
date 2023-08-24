#include <iostream>
using namespace std;

class Node{
    public:
    int val;
    Node* next;
    Node* bottom;
    Node(int data = 0){
        this->val = data;
        this->next = NULL;
        this->bottom = NULL;
    }
    ~Node(){
        cout<<"Deleted: "<<this->val<<endl;
        this->next = NULL;
        this->bottom = NULL;
        delete next;
    }
};

void print(Node* &head){
    Node* temp = head;

    while(temp){
        cout<<temp->val<<" ";
        Node* temp2 = temp->bottom;
        while(temp2){
            cout<<temp2->val<<" ";
            temp2 = temp2->bottom;
        }
        temp = temp->next;
        cout<<endl;
    }
    cout<<endl;
}

Node* merge(Node* a, Node* b){
    if(!a) return b;
    if(!b) return a;

    Node* ans = NULL;
    if(a->val < b->val){
        ans = a;
        a->bottom = merge(a->bottom,b);
    }
    else{
        ans = b;
        b->bottom = merge(a,b->bottom);
    }
    return ans;
}

Node* flatten(Node* head){
    if(!head) return NULL;
    Node* merged = merge(head,flatten(head->next));
    return merged;
}

int main()
{
    Node* head1 = new Node(5); 
    Node* sec = new Node(6); 
    Node* third = new Node(7); 
    Node* forth = new Node(8);
    Node* head2 = new Node(10);
    Node* sixth = new Node(30);
    // Node* seventh = new Node(26);
    // Node* eighth = new Node(90);
    // Node* ninth = new Node(223);
    // Node* tenth = new Node(689);

    head1->bottom = sec;
    sec->bottom = third;
    third->bottom = forth;
    head1->next = head2;
    head2->bottom = sixth;
    
    // seventh->next = eighth;
    // eighth->next = ninth;
    // ninth->next = tenth;
    // tenth->next = NULL;

    // Node* temp = printKthNode(head,0);
    // cout<<temp->val<<endl;
    // int ans;
    // int k = 6;
    // cout<<ans<<endl;
    
    print(head1);
    return 0;
}