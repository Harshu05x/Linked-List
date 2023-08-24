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

// Two Pointer Approach
// slow-fast pointer approach
// tortoise algorithm
Node* findMiddle(Node* head){
    if(!head || !head->next)
        return head;
    
    Node* slow = head;      // slow ptr moves 1 steps
    Node* fast = head;      // fast ptr moves 2 steps

    while(slow && fast){
        fast = fast->next;
        if(fast != NULL){
            fast = fast->next;
            slow = slow->next;
        }
    }
    return slow;
}

// Navie Approach
Node* findMiddle_01(Node* head){
    if(!head || !head->next)
        return head;
    int len = length(head);
    int i = 0;
    Node* temp = head;
    while(i < len/2){
        temp = temp->next;
        i++;
    }
    return temp;
}

int main()
{
    Node* head = new Node(10); 
    Node* first = new Node(20); 
    Node* second = new Node(30); 
    Node* third = new Node(40); 
    Node* forth = new Node(50); 
    // Node* fifth = new Node(60);

    head->next = first;
    first->next = second;
    second->next = third;
    third->next = forth;
    forth->next = NULL;
    // fifth->next = NULL;

    print(head);
    cout<<"Middle: "<<findMiddle(head)->data<<endl;
    cout<<"Middle: "<<findMiddle_01(head)->data<<endl;
    return 0;
}