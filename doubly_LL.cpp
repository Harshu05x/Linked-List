#include <iostream>
using namespace std;

class Node
{
public:
    Node *prev;
    int data;
    Node *next;
};
class LinkedList
{
public:
    Node *first;

    LinkedList()
    {
        this->first = NULL;
    }
    LinkedList(int A[], int n)
    {
        Node *t, *last;
        first = new Node;
        first->data = A[0];
        first->prev = first->next = NULL;
        last = first;

        for (int i = 1; i < n; i++)
        {
            t = new Node;
            t->data = A[i];
            t->next = last->next;
            t->prev = last;
            last->next = t;
            last = t;
        }
    }
    ~LinkedList()
    {
        Node *p = first;
        while (first)
        {
            first = first->next;
            delete p;
            p = first;
        }
    }

    void display();
    void insert(int index, int x);
    int delet(int index);
    void reverse();
};

void LinkedList::display()
{
    Node *p = first;
    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }
}

void LinkedList::insert(int index, int x)
{
    Node *p = first, *t;
    t = new Node;
    t->data = x;
    if (index == 0)
    {
        t->prev = NULL;
        t->next = first;
        first->prev = t;
        first = t;
    }
    else
    {
        for (int i = 0; i < index - 1; i++)
            p = p->next;
        t->next = p->next;
        t->prev = p;
        if (p->next)
        {
            p->next->prev = t;
            p->next = t;
        }
    }
}

int LinkedList::delet(int index){
    Node *p = first;
    int x;
    if(index == 0){
        first = first->next;
        if(first) first->prev = NULL;
        x = p->data;
        delete p;
    }
    else {
        for(int i = 0;i < index;i++) p = p->next;
        p->prev->next = p->next;
        if(p->next) p->next->prev = p->prev;
        x = p->data;
        delete p;
    }
    return x;
}
void LinkedList::reverse(){
    Node *p = first;
    while(p != NULL){
        swap(p->next,p->prev);
        p = p->prev;
        if(p != NULL && p->next == NULL) first =p;
    }
}
int main()
{
    int A[] = {1, 3, 5, 7, 9};
    LinkedList L1(A, 5);
    int index, x;
    L1.reverse();
    L1.display();
    // cout<<endl;
    // // cout << "Enter ele: ";
    // // cin >> x;
    // cout << "Enter it's index: ";
    // cin >> index;
    // // L1.insert(index, x);
    // cout<<"Element deleted: "<<L1.delet(index)<<endl;

    // L1.display();

    return 0;
}