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
// Iterative Apporach
Node* printKthNode(Node* &head, int k){
    int len = length(head);

    if(head == NULL || k > len)
        return NULL;
    
    int kth = len - k - 1;
    
    Node* temp = head;
    while(kth-- && temp)
        temp = temp->next;
    return temp;
}

// Recursive Apporach
void printKthNode_01(Node* temp, int &k, int &ans){
    if(temp == NULL)
        return;

    printKthNode_01(temp->next,k,ans);
    
    if(k == 0)
        ans = temp->val;
    k--;
}
int main()
{
    Node* head = new Node(121); 
    Node* sec = new Node(2); 
    Node* third = new Node(33); 
    Node* forth = new Node(16);
    Node* fifth = new Node(55);
    Node* sixth = new Node(69);
    Node* seventh = new Node(26);
    Node* eighth = new Node(90);
    Node* ninth = new Node(223);
    Node* tenth = new Node(689);

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

    // Node* temp = printKthNode(head,0);
    // cout<<temp->val<<endl;
    int ans;
    int k = 6;
    printKthNode_01(head,k,ans);
    cout<<ans<<endl;
    
    return 0;
}