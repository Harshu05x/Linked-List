#include <iostream>
#include <vector>
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

// Constraints:
// 1] The number of nodes in the list is in the range [3, 2 * 105].
// 2] 0 <= Node.val <= 1000
// 3] There are no two consecutive nodes with Node.val == 0.
// 4] The beginning and end of the linked list have Node.val == 0.
Node* mergeNodes(Node* &head){
    Node* slow = head;
    Node* fast = head->next;
    Node* lastNode = NULL;
    int sum = 0;
    while(fast){
        if(fast->val != 0)
            sum += fast->val;
        else{
            slow->val = sum;
            lastNode = slow;
            slow = slow->next;
            sum = 0;
        }
        fast = fast->next;
    }
    lastNode->next = NULL;
    while(slow){
        Node* temp = slow->next;
        delete slow;
        slow = temp;
    }
    return head;
}

int main(){

    Node* head = new Node(0); 
    Node* sec = new Node(3); 
    Node* third = new Node(1); 
    Node* forth = new Node(0);
    Node* fifth = new Node(4);
    Node* sixth = new Node(2);
    Node* seventh = new Node(5);
    Node* eighth = new Node(0);
    Node* ninth = new Node(7);
    Node* tenth = new Node(0);

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

    mergeNodes(head);
    print(head);
    return 0;
}

