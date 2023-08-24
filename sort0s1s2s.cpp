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

// Counting Approach ( using data replacement )
void sort0s1s2s(Node* &head){
    // If LL is empty
    if(head == NULL)
        return;
    
    // If single node is present 
    if(head->next == NULL)
        return ;

    int zeros = 0;
    int ones = 0;
    int twos = 0;

    Node* temp = head;
    // 1] Find count of zeros , ones & twos
    while(temp){
        if(temp->data == 0)
            zeros++;
        else if(temp->data == 1)
            ones++;
        else if(temp->data == 2)
            twos++;
        temp = temp->next;
    }

    // 2] fill LL with count of  zeros , ones & twos
    temp = head;
    // fill zeros
    while(zeros--){
        temp->data = 0;
        temp = temp->next;
    }
    // fill ones
    while(ones--){
        temp->data = 1;
        temp = temp->next;
    }
    // fill twos
    while(twos--){
        temp->data = 2;
        temp = temp->next;
    }
    
}

// sorting without data replacement ( links are replaced here )
// It's more preferable & advisable
Node* sort0s1s2s_01(Node* &head){
    // If LL is empty
    if(head == NULL)
        return NULL;
    
    // If single node is present 
    if(head->next == NULL)
        return head;

    // 1] Create Dummy Nodes
    Node* zeroHead = new Node(-1);
    Node* zeroTail = zeroHead;

    Node* oneHead = new Node(-1);
    Node* oneTail = oneHead;

    Node* twoHead = new Node(-1);
    Node* twoTail = twoHead;

    // 2] Traverse the LL
    Node* curr = head;
    while(curr){
        if(curr->data == 0){
            // Take out zero wali node
            Node* temp = curr;
            curr = curr->next;
            temp->next = NULL;

            // append that node In zeroHead LL
            zeroTail->next = temp;
            zeroTail = temp;
        }
        else if(curr->data == 1){
            // Take out one wali node
            Node* temp = curr;
            curr = curr->next;
            temp->next = NULL;

            // append that node In oneHead LL
            oneTail->next = temp;
            oneTail = temp;
        }
        else if(curr->data == 2){
            // Take out two wali node
            Node* temp = curr;
            curr = curr->next;
            temp->next = NULL;

            // append that node In twoHead LL
            twoTail->next = temp;
            twoTail = temp;
        }
    }

    // Now we are ready with LLs of zeros , ones & twos
    // 3] Modifiy one wali & two wali dummy nodes
    Node* temp = oneHead;
    oneHead = oneHead->next;
    delete temp;

    temp = twoHead;
    twoHead = twoHead->next;
    delete temp;

    // 4] Join all three LLs
    if(oneHead != NULL){
        // one wali LL is not empty
        zeroTail->next = oneHead;
        if(twoHead != NULL){    
            oneTail->next = twoHead;
        }
    }
    else{
        // one wali LL is empty
        if(twoHead != NULL)
            zeroTail->next = twoHead;
    }
    
    // 4] Remove zero wali dummy Nodes
    temp = zeroHead;
    zeroHead = zeroHead->next;
    delete temp;
    // 5] bring head at it's right pos & return head
    head = zeroHead;
    return head;

}

int main()
{
    Node* head = new Node(2); 
    Node* first = new Node(2); 
    Node* second = new Node(2); 
    Node* third = new Node(2); 
    Node* forth = new Node(2); 
    Node* fifth = new Node(2);
    Node* sixth = new Node(2);

    head->next = first;
    first->next = second;
    second->next = third;
    third->next = forth;
    forth->next = fifth;
    fifth->next = sixth;
    sixth->next = NULL;

    print(head);
    head = sort0s1s2s_01(head);
    print(head);
    return 0;
}