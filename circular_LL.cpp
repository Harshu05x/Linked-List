#include <iostream>
using namespace std;

class Node{
    public: 
    int data;
    Node *next;
};

class LinkedList{
    public:
    Node *first;
    LinkedList(){
        first = NULL;
    }
    LinkedList(int A[],int n){
        int i;
        Node *t,*last;
        first = new Node;
        first->data = A[0];
        first->next = first;
        last = first;

        for(i = 1; i<n; i++){
            t = new Node;
            t->data = A[i];
            t->next = last->next;
            last->next = t;
            last = t;
        }
    }
    ~LinkedList(){
        Node *p = first;
        while(first){
            first = first->next;
            delete p;
            p = first;
        }
    }
    void display();
    void Rdisplay(Node *p);
    void insert(int index, int x);
    int Delete(int index);
};
void LinkedList::display(){
    Node *p = first;
    do{
        cout<<p->data<<" ";
        p = p->next;
    }while(p != first);
}
void LinkedList::Rdisplay(Node *p){
    static int flag = 0;
    if(p != first || flag == 0){
        flag = 1;
        cout<<p->data<<" ";
        Rdisplay(p->next);
    }
    flag = 0;
}
void LinkedList::insert(int index, int x){
    Node *p = first;
    Node *t;
    int i;
    if(index == 0){
        t = new Node;
        t->data = x;
        if(first == NULL){
            first = t;
            first->next = first;
        }
        else{
            while(p->next != first) p = p->next;
            p->next = t;
            t->next = first; 
            first = t;
        }
    }
    else{
        t = new Node;
        t->data = x;
        for(i=0;i<index-1;i++) p = p->next;
        t->next = p->next;
        p->next = t;
    }
}
int LinkedList::Delete(int index){
    Node *p = first;
    Node *q;
    int x;
    if(index == 1){
       while(p->next != first) p = p->next;
        x = first->data;
        if(p == first){
            delete first;
            first = NULL;
        }
        else{
            p->next = first->next;
            delete first;
            first = p->next;
        }
    }
    else{
        for(int i=0;i<index-2;i++) p = p->next;
        q = p->next;
        p->next = q->next;
        x = q->data;
        delete q;
    }
    return x;
}
int main()
{
    int A[] = {1,3,5,7,9};
    LinkedList L1(A,5);
    int index , x;

    cout<<"Enter the index of ele u want to delete: ";
    cin>>index;
    cout<<"Element deleted: "<<L1.Delete(index)<<endl;

    // cout<<"Enter an ele u want to insert: ";
    // cin>>x;
    // cout<<"Enter it's index: ";
    // cin>>index;
    // L1.insert(index,x);
    
    cout<<"Elements--> ";
    L1.Rdisplay(L1.first);

    return 0;
}