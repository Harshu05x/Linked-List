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

void print(Node* &head){
    Node* temp = head;

    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int length(Node* head){
    Node* temp = head;
    int n = 0;
    while(temp){
        n++;
        temp = temp->next;
    }
    return n;
}

Node* reverseKnodes(Node* head, int k){
    if(head == NULL)
        return NULL;
    if(k > length(head))
        return head;
    
    Node* p = NULL, *q = head, *r = NULL;
    int count = 0;
    
    // 1] Reverse first K nodes
    while(count < k){
        p = q->next;
        q->next = r;
        r = q; 
        q = p;
        count++;
    }

    // 2] recursive call n attach next nodes to head
    if(p != NULL){
        head->next = reverseKnodes(p,k);
    }

    // 3] return a node "r" as head of modified LL
    return r;

}

int main()
{
    Node* head = new Node(10); 
    Node* first = new Node(20); 
    Node* second = new Node(30); 
    Node* third = new Node(40); 
    Node* forth = new Node(50); 
    Node* fifth = new Node(60);

    head->next = first;
    first->next = second;
    second->next = third;
    third->next = forth;
    forth->next = fifth;
    fifth->next = NULL;

    print(head);

    head = reverseKnodes(head,3);

    print(head);
    return 0;
}