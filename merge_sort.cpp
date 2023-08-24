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

// Finds the middle node
Node* findMid(Node* &head){
    Node* slow = head;
    Node* fast = head->next;

    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

// Iterative Apporach to merge two sorted LLs
Node* mergeTwoLists(Node* &list1, Node* &list2) {
    if(list1 == NULL || list2 == NULL){
        return list1 == NULL ? list2 : list1;
    }
    Node* ansHead = new Node(-1);
    Node* ansTail = ansHead;

    while(list1 && list2){
        if(list1->val <= list2->val){
            ansTail->next = list1;
            ansTail = list1;
            list1 = list1->next;
        }
        else{
            ansTail->next = list2;
            ansTail = list2;
            list2 = list2->next;
        }
    }
    if(list1)
        ansTail->next = list1;
    
    if(list2)
        ansTail->next = list2;
    
    return ansHead->next;
}

Node* mergeSort(Node* &head){
    if(head == NULL || head->next == NULL)
        return head;
    
    // Break LL into 2 halves using mid node
    Node* mid = findMid(head);
    Node* left = head;
    Node* right = mid->next;
    mid->next = NULL;

    // Make sort RE calls
    left = mergeSort(left);
    right = mergeSort(right);

    // merge both left & right sorted LLs
    Node* ans = mergeTwoLists(left,right);
    return ans;
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
    Node* ninth = new Node(-23);
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

    print(head);
    Node* ansHead = mergeSort(head);
    print(ansHead);
    return 0;
}