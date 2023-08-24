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

// Iterative Apporach
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
    
    Node* temp = ansHead;
    ansHead = ansHead->next;
    delete temp;

    return ansHead;
}


int main()
{
    Node* list1 = new Node; 
    Node* sec1 = new Node(2); 
    Node* third1 = new Node(3); 
    Node* forth1 = new Node(6); 
    list1->next = sec1;
    sec1->next = third1;
    third1->next = forth1;

    Node* list2 = new Node(1); 
    Node* sec2 = new Node(3); 
    Node* third2 = new Node(4); 
    // Node* forth2 = new Node(); 
    list2->next = sec2;
    sec2->next = third2;
    // third2->next = forth2;

    Node* ansHead = mergeTwoLists(list1,list2);
    print(ansHead);
    return 0;
}