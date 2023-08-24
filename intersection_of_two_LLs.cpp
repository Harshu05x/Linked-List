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

unordered_map<Node*,bool> mp;
Node* getIntersection(Node* &list1, Node* &list2){
    Node* temp = list1;
    while(temp){
        mp[temp] = true;
        temp = temp->next;
    }

    temp = list2;
    while(!mp[temp] && temp){
        temp = temp->next;
    }
    return temp;
}

Node* getIntersection_02(Node* &list1, Node* &list2){
    Node* a = list1;
    Node* b = list2;
    
    while(a->next && b->next){
        if(a == b)
            return a;
        a = a->next;
        b = b->next;
    }

    if(a->next == NULL && b->next == NULL && a != b) return NULL;

    if(a->next == NULL){
        // It mean B is bigger or equal
        int blen = 0;
        while(b->next){
            blen++;
            b = b->next;
        }
        while(blen--){
            list2 = list2->next;
        }
    }
    else{
        // It mean A is bigger
        int alen = 0;
        while(a->next){
            alen++;
            a = a->next;
        }
        while(alen--){
            list1 = list1->next;
        }
    }

    while(list1 != list2){
        list1 = list1->next;
        list2 = list2->next;

    }
    return list1;
}
int main(){

    Node* head1 = new Node(4);
    Node* sec1 = new Node(1);
    Node* third1 = new Node(8);
    Node* forth1 = new Node(4);
    Node* fifth1 = new Node(5);
    head1->next = sec1;
    sec1->next = third1;
    third1->next = forth1;
    forth1->next = fifth1;

    Node* head2 = new Node(5);
    Node* sec2 = new Node(6);
    Node* third2 = new Node(1);
   
    head2->next = sec2;
    sec2->next = third2;
    third2->next = third1;
    Node* ans = getIntersection_02(head1,head2);
    print(ans);
    return 0;
}