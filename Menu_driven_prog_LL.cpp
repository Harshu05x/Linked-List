#include <iostream>
// #include "Display.cpp"
using namespace std;

class Node{
    public:
    int data;
    Node *next;
};

class LinkedList{
    private:
    Node *first;
    Node *second;
    public:
    LinkedList() {first = NULL, second = NULL;}
    LinkedList(int A[], int n);
    ~LinkedList();

    void display();
    void insert(int x, int pos);
    void delet(int pos);
    int sum();
    int length();
    void reverse();
    void max_min();
    void linear_search(int x);
    void isSort();
    void merge(LinkedList l1,LinkedList l2);
    void remove_duplicate();
    
};

// It's a Parameterised Constructor for class
LinkedList::LinkedList(int A[],int n){
    int i;
    Node *t,*last;
    first = new Node;
    first->data = A[0];
    first->next = NULL;
    last = first;

    for(i = 1; i<n; i++){
        t = new Node;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

// It's a Destructor for a class 
LinkedList::~LinkedList(){
    Node *p = first;
    while(first){
        first = first->next;
        delete p;
        p = first;
    }
}

// Display all ele in Linked list
void LinkedList::display() {
    Node *p = first;
    while(p){
        cout<<p->data<<" ";
        p = p->next;
    }
}

// Insert a given ele at given pos
void LinkedList::insert(int x, int pos){
    Node *t,*p;
    if(pos == 0){
        t = new Node;
        t->data = x;
        t->next = first;
        first = t;
    }
    else if(pos > 0){
        p = first;
        for(int i = 0;i < pos-1 && p;i++) p = p->next;
        if(p){
            t = new Node;
            t->data = x;
            t->next = p->next;
            p->next = t;
        }
    }
}

// It will delete element at given index
void LinkedList::delet(int pos){
    Node *p = first,*q = NULL;
    int x;
    if(pos == 0){
        first = first->next;
        x = p->data;
        delete p;
    }
    else {
        for(int i = 0; i < pos && p;i++){
            q = p;
            p = p->next;
        }
        q->next = p->next;
        x = p->data;
    }
    delete p;
    cout<<"Element deleted : "<<x;
}  

// Gives sum of all elemments in LL
int LinkedList::sum(){
    int sum = 0;
    Node *p = first;
    while(p){
        sum += p->data;
        p = p->next;
    }
    return sum;
}

// Gives length of a LL
int LinkedList::length(){
    int length = 0;
    Node *p = first;
    while(p){
        length++;
        p = p->next;
    }
    return length;
}

// It reverse a LL
void LinkedList::reverse(){
    Node *p = first;
    Node *q = NULL,*r = NULL;
    while(p){
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    first = q;
}

// Gives maximum and minimun ele in a LL
void LinkedList::max_min(){
    int max = INT32_MIN;
    int min = INT32_MAX;
    Node *p = first;
    while(p){
        if(p->data > max) max = p->data;
        if(p->data < min) min = p->data;
        p = p->next;
    }
    cout<<"Maximum element: "<<max<<endl;
    cout<<"Minimum element: "<<min;
} 

// Perform linear search on LL and find given ele
void LinkedList::linear_search(int x){
    Node *p = first;
    int index = 0,result = 0;
    while(p){
        if(p->data == x){
            cout<<"Element is found at index: "<<index;
            result = 1;
            break;
        }
        p = p->next;
        index++;
    }
    if(result == 0) cout<<"Element is not found";
}

// It checks if a gievn LL is sorted or not
void LinkedList::isSort(){
    int result = 0;
    int max = INT32_MIN;
    Node *p = first;
    while(p){
        if(p->data < max){
            cout<<"Given Linked List is not sorted.";
            result = 1;
            break;
        }
        max = p->data;
        p = p->next;
    }
    if(result == 0) cout<<"Given Linked List is sorted.";
}

// Merge two sorted LL
void LinkedList::merge(LinkedList l1, LinkedList l2){
    Node *t = NULL,*last;
    Node *p = l1.first,*q = l2.first;
    if(p->data < q->data){
        last = t = p;
        p = p->next;
        last->next = NULL;
    }
    else{
        last = t = q;
        q = q->next;
        last->next = NULL;
    }
    while(p && q){
        if(p->data < q->data){
            last->next = p;
            last = p;
            p = p->next;
            last->next = NULL;
        }
        else {
            last->next = q;
            last = q;
            q = q->next;
            last->next = NULL;
        }
        if(p) last->next = p;
        else last->next = q;
    }
}

// It will remove duplicate elements in a sorted LL
void LinkedList::remove_duplicate(){
    Node *p = first;
    Node *q = first->next;
     while(q){
        if(p->data != q->data){
            p = q;
            q = q->next;
        }
        else{
            p->next = q->next;
            delete q;
            q = p->next;
        }
    }
    cout<<"Duplicate elements are removed."<<endl;
}
int main()
{   
    int x,pos;
    int A[] = {1,3,5,7,9};
    int B[] = {2,4,6,8,10};
    LinkedList l(A,5);
    LinkedList l2(B,5);
    int choice;
    
    do{
        cout<<endl;
        cout<<"\t---Menu---\t"<<endl;
        cout<<"1. Display"<<endl;
        cout<<"2. Insert"<<endl;
        cout<<"3. Delete"<<endl;
        cout<<"4. Sum"<<endl;
        cout<<"5. Length"<<endl;
        cout<<"6. Reverse"<<endl;
        cout<<"7. Max and Min"<<endl;
        cout<<"8. Linear Search"<<endl;
        cout<<"9. Check Sort"<<endl;
        cout<<"10. Merge"<<endl;
        cout<<"11. Remove Duplicates"<<endl;
        cout<<"12. Exit"<<endl;
        cout<<"Enter your choice: "<<endl;
        cin>>choice;

        switch (choice)
        {
        case 1: cout<<"Linked List--> ";
                l.display();
                cout<<endl;
            break;
        case 2: cout<<"Enter ele u want to insert: ";
                cin>>x;
                cout<<"Enter position at which u want to insert: ";
                cin>>pos;
                l.insert(x,pos);
                cout<<"Element inserted.";
                cout<<endl;
            break;
        case 3: cout<<"Enter an index of element u want to delete: ";
                cin>>pos;
                l.delet(pos);
                cout<<endl;
            break;
        case 4: cout<<"Sum of all ele in LL: ";
                cout<<l.sum();
                cout<<endl;
            break;
        case 5: cout<<"Length of LL: ";
                cout<<l.length();
                cout<<endl;
            break;
        case 6: l.reverse();
                cout<<"Linked list is reversed.";
                cout<<endl;
            break;
        case 7: l.max_min();
                cout<<endl;
            break;
        case 8: cout<<"Enter an ele u want to search: ";
                cin>>x;
                l.linear_search(x);
                cout<<endl;
            break;
        case 9: l.isSort();
                cout<<endl;
            break;
        case 10: l2.merge(l,l2);
                 l2.display();
                 cout<<endl;
            break;
        case 11: l2.remove_duplicate();
                 l2.display();
                 cout<<endl;
            break;
        case 12: cout<<"\t---Thank You---"<<endl;         
            break;
        default : cout<<"Oops! Invalid Option. Try again."<<endl;
        
        };
    }while(choice != 12);
    return 0;
}