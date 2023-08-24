#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int data = 0){
        this->data = data;
        this->next = nullptr;
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

int main()
{
    Node* first = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* forth = new Node(40);
    Node* fifth = new Node();

    first->next = second;
    second->next = third;
    third->next = forth;
    forth->next = fifth;

    print(first);

    return 0;
}