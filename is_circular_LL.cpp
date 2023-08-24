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
        if(temp == head)
            break;
    }
    cout<<endl;
}

// using 1 ptr
bool is_circular(Node* &head){
    if(head == NULL)
        return false;
    if(head->next == NULL)
        return true;

    Node* temp = head->next;
    while(temp){
        temp = temp->next;
        if(temp == head)
            return true;
    }
    return false;
}

// two pointer approach
// slow-fast pointer approach
bool is_circular_01(Node* &head){
    Node* slow = head;
    Node* fast = head;

    while(slow && fast){
        fast = fast->next;
        if(fast != NULL){
            fast = fast -> next;
            slow = slow -> next;
        }
        if(fast == slow) return true;
    }
    return false;
}

// using map
unordered_map<Node*,bool> mp;
bool is_circular_02(Node* &head){
    Node* temp = head;

    while(temp){
        if(mp[temp] == true)
            return temp;
        mp[temp] = true;
        temp = temp -> next;
    }
    return false;
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

    cout<<is_circular(head)<<endl;
    cout<<is_circular_01(head)<<endl;
    cout<<is_circular_02(head)<<endl;

    print(head);
    return 0;
}