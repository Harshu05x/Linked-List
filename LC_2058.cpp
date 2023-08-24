#include <iostream>
#include <vector>
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

vector<int> nodesBetweenCriticalPoints(Node* head) {
    // 0 node present
    Node* prev = head;
    if(!prev) return {-1,-1};

    // 1 node present 
    Node* curr = head->next;
    if(!curr) return {-1,-1};

    // 2 nodes present
    Node* nxt = head->next->next;
    if(!nxt) return {-1,-1};

    // 3 nodes present
    if(!nxt->next) return {-1,-1};

    int firstCP = -1;
    int lastCP = -1;
    int minDist = INT32_MAX;
    int i = 0;

    while(nxt){
        // Check if CP is present or not
        bool isCP = ((curr->val < prev->val && curr->val < nxt->val) || 
                        (curr->val > prev->val && curr->val > nxt->val))
                            ? true : false;
        
        // CP found and it's a first CP
        if(isCP && firstCP == -1){
            firstCP = i;
            lastCP = i;
        }
        else if(isCP){
            minDist = min(minDist,i-lastCP);
            lastCP = i;
        }
        i++;
        prev = prev->next;
        curr = curr->next;
        nxt = nxt->next;
    }
    // it means only one CP is present
    if(lastCP == firstCP)
        return {-1,-1};
    return {minDist,lastCP-firstCP};
}

int main(){

    Node* head = new Node(1); 
    Node* sec = new Node(3); 
    Node* third = new Node(2); 
    Node* forth = new Node(2);
    Node* fifth = new Node(3);
    Node* sixth = new Node(2);
    Node* seventh = new Node(2);
    Node* eighth = new Node(2);
    Node* ninth = new Node(7);
    Node* tenth = new Node(1);

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
    vector<int> ans = nodesBetweenCriticalPoints(head);
    for(auto i : ans) cout<<i<<" ";
    return 0;
}

