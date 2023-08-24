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

// two pointer approach
// slow-fast pointer approach
Node* removeLOOP(Node* &head){
    if(head == NULL)
        return NULL;

    Node* slow = head;
    Node* fast = head;
    // 1] Detect a LOOP
    while(fast){
        fast = fast->next;
        if(fast != NULL){
            fast = fast -> next;
            slow = slow -> next;
        }
        if(fast == slow){
            // if slow == head then ->
            if(slow == head){
                Node* temp = head->next;
                while(temp->next != head){
                    temp = temp->next;
                }
                temp->next = NULL;
                return head;
            }
            // after detection of loop slow point on head
            slow = head;
            break;
        }
    }
    // traverse list with moving slow n fast by 1step
    Node* prev = NULL;      // keep a prev ptr which is 
                            // just behind of fast ptr
    while(slow != fast){
        prev = fast;
        slow = slow->next;
        fast = fast->next;
    }
    // removing LOOP by cutting the link
    prev->next = NULL;
    return head;
}

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


int main()
{
    Node* head = new Node(10); 
    Node* first = new Node(20); 
    Node* second = new Node(30); 
    Node* third = new Node(40); 
    Node* forth = new Node(50); 
    Node* fifth = new Node(60);
    Node* sixth = new Node(70);
    Node* seventh = new Node(80);
    Node* eighth = new Node(90);
    Node* ninth = new Node(100);

    head->next = first;
    first->next = second;
    second->next = third;
    third->next = forth;
    forth->next = fifth;
    fifth->next = sixth;
    sixth->next = seventh;
    seventh->next = eighth;
    eighth->next = ninth;
    ninth->next = head;

    cout<<"Loop present: "<<is_circular_01(head)<<endl;
    removeLOOP(head);
    cout<<"Loop present: "<<is_circular_01(head)<<endl;
    print(head);

    return 0;
}