#include <iostream>
#include <unordered_map>
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

bool isPalindrome(Node* &head){
    if(head == NULL || head->next == NULL)
        return true;

    // 1] find middle node
    Node* slow = head, *fast = head->next;
    while(fast){
        fast = fast->next;
        if(fast != nullptr){
            fast = fast->next;
            slow = slow->next;
        }
    }
    
    // 2] reverse LL after slow th node
    Node* p = NULL, *q = slow->next, *r = NULL;
    while(q){
        p = q->next;
        q->next = r;
        r = q;
        q = p;
    }
    // Join both LL 
    slow->next = r;
    // 3] Compare both LL 
    Node* temp1 = head, *temp2 = r;
    while(temp2){
        if(temp1->data != temp2->data)
            return false;
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return true;
}

int main()
{
    Node* head = new Node(10); 
    Node* first = new Node(20); 
    Node* second = new Node(30); 
    Node* third = new Node(20); 
    Node* forth = new Node(10); 
    // Node* fifth = new Node(10);

    head->next = first;
    first->next = second;
    second->next = third;
    third->next = forth;
    forth->next = NULL;
    // fifth->next = NULL;

    print(head);
    cout<<isPalindrome(head)<<endl;
    print(head);

    return 0;
}