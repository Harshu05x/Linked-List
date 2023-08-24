#include <iostream>
using namespace std;

class Node{
    public:
    Node* prev;
    int data;
    Node* next;

    Node(int data = 0){
        this->prev = NULL;
        this->data = data;
        this->next = NULL;
    }
    ~Node(){
        cout<<"Deleted: "<<this->data<<endl;
        prev = NULL;
        next = NULL;
        delete prev;
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
int length(Node* &head){
    Node* temp = head;
    int c = 0;
    while(temp){
        c++;
        temp = temp->next;
    }
    return c;
}

int main()
{
     
    return 0;
}