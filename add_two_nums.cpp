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
    ~Node(){
        cout<<"Deleted Node: "<<this->data<<endl;
        this->next = NULL;
        delete next;
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

Node* reverseLL(Node* &head){
    Node* p = NULL, *q = head, *r = NULL;

    while(q){
        p = q->next;
        q->next = r;
        r = q;
        q = p;
    }
    return r;
}

Node* solve(Node* &head1, Node* &head2){
    if(head1 != NULL || head2 != NULL){
        return head1 == NULL ? head2 : head1;
    }
    // 1] Reverse both LLs
    head1 = reverseLL(head1);
    head2 = reverseLL(head2);

    // 2] Add both reversed LLs
    Node* ansHead = NULL;
    Node* ansTail = NULL;
    int sum = 0, digit = 0, carry = 0;
    while(head1 && head2){
        // calculate sum
        sum = carry + head1->data + head2->data;
        // find digit for node creation        
        digit = sum % 10;
        // calculate carry
        carry = sum / 10;

        // create a node for carry
        Node* temp = new Node(digit);
        if(ansHead == NULL){
            // it's mean ur inerting in empty LL
            ansHead = temp;
            ansTail = temp;
        }
        else{
            ansTail->next = temp;
            ansTail = temp;
        }
        head1 = head1->next;
        head2 = head2->next;
    }

    // if (len of head1 LL) > (len of head2 LL)
    while(head1){
        sum = carry + head1->data;
        digit = sum % 10;
        carry = sum / 10;

        Node* temp = new Node(digit);
        ansTail->next = temp;
        ansTail = temp;
        head1 = head1->next;
    }
    // if (len of head1 LL) < (len of head2 LL)
    while(head2){
        sum = carry + head2->data;
        digit = sum % 10;
        carry = sum / 10;

        Node* temp = new Node(digit);
        ansTail->next = temp;
        ansTail = temp;
        head2 = head2->next;
    }
    if(carry != 0){
        Node* temp = new Node(carry);
        ansTail->next = temp;
        ansTail = temp;
    }
    // 3] Reverse the ans wali LL
    return reverseLL(ansHead);
}

int main(){

    Node* head1 = new Node(2);
    Node* sec1 = new Node(4);
    Node* third1 = new Node(9);
    head1->next = sec1;
    sec1->next = third1;

    Node* head2 = new Node(5);
    Node* sec2 = new Node(6);
    Node* third2 = new Node(4);
    Node* forth2 = new Node(9);
    head2->next = sec2;
    sec2->next = third2;
    third2->next = forth2;
    print(head1);
    print(head2);
    Node* ans = solve(head1,head2);
    print(ans);
    return 0;
}