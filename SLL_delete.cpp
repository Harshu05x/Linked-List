#include <iostream>
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
        cout<<"Deleted: "<<this->data<<endl;
        next = NULL;
        delete next;
    }
};

int len(Node* &head){
    Node* temp = head;
    int c = 0;
    while(temp){
        c++;
        temp = temp->next;
    }
    return c;
}
void insertAtHead(Node* &head, int data){
    Node* temp = new Node(data);
    temp->next = head;
    head = temp;
}

void deleteFromHead(Node* &head){
    if(head == NULL){
        cout<<"LL is empty\n";
        return;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
}

void deleteFromEnd(Node* &head){
    if(head == NULL){
        cout<<"LL is empty\n";
        return;
    }
    Node* temp = head, *p = NULL;

    while(temp->next){
        p = temp;
        temp = temp->next;
    }
    delete temp;

}

void deleteFromMiddle(Node* &head, int index){
    if(head == NULL){
        cout<<"LL is empty\n";
        return;
    }
    if(index == 0){
        deleteFromHead(head);
        return;
    }
    int i = 1;
    Node* p = head, *q = NULL;
    while(i <= index && p->next){
        q = p ;
        p = p->next;
        i++;
    }
    q->next = p->next;
    delete p;
}

void deleteNode(Node* &head, int pos){
    if(head == NULL ){
        cout<<"LL is empty\n";
        return;
    }
    // 1] Create a node n point on Head
    Node* temp = head;

    //  if pos == 0 then delete from head;
    if(pos == 0){
        head = head->next;
        delete temp;
    }
    else{
        // find length 
        int length = len(head);
        if(pos >= length){
            cout<<"Invalid pos"<<endl;
            return ;
        }
        else{
        
            Node* p = NULL;
            int i = 1;
            // find pos of node
            while(i <= pos){
                p = temp;
                temp = temp->next;
                i++;
            }
            // logic to delete node
            p->next = temp->next;
            delete temp;
        }    
    }
}

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
    
    Node* head = NULL;
    insertAtHead(head,60);
    insertAtHead(head,50);
    insertAtHead(head,40);
    insertAtHead(head,30);
    insertAtHead(head,20);
    insertAtHead(head,10); 
    cout<<"Length: "<<len(head)<<endl;
    deleteNode(head,5);
    deleteNode(head,0);
    deleteNode(head,2);
    print(head);
    return 0;
}