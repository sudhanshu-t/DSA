#include<bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node* next;
};


Node* merge(Node* h1, Node* h2){
    Node* head;

    if(h1->data >= h2->data){
        head = new Node();
        head->data = h1->data;
        Node* rem = h1;
        h1 = h1->next;
        rem->next = NULL;
        delete rem;
    } else {
        head = new Node();
        head->data = h2->data;
        Node* rem = h2;
        h2 = h2->next;
        rem->next = NULL;
        delete rem;
    }
    
    Node* temp = head;
    
    while(h1 != NULL && h2 != NULL){
        if(h1->data >= h2->data){
            temp->next = h1;
            temp = temp->next;
            
            h1 = h1->next;
            
            temp->next = NULL;
        } else {
            temp->next = h2;
            temp = temp->next;
            
            h2 = h2->next;
            
            temp->next = NULL;
        }
    }
    
    if(h1 == NULL){
        temp->next = h2;
        return head;
    } else {
        temp->next = h1;
        return head;
    }
}

Node* rpi(Node* head){
    if(head->next == NULL){
        return head;
    }
    
    Node* prev = NULL;
    Node* curr = head;
    Node* next = head->next;
    
    while(curr != NULL){
        curr->next = prev;
        prev = curr;
        curr = next;
        
        if(next != NULL)
            next = next->next;
    }
    
    return prev;
}

struct Node * mergeResult(Node *node1,Node *node2)
{
    // your code goes here
    if(node1 == NULL || node2 == NULL){
        return (node1 == NULL) ? rpi(node2) : rpi(node1);
    }
    
    node1 = rpi(node1);
    node2 = rpi(node2);
    
    node1 = merge(node1, node2);
    return node1;
}


void print(struct Node *Node)
{
    while (Node!=NULL)
    {
        cout << Node->data << " ";
        Node = Node->next;
    }
}
struct Node * mergeResult(struct Node *node1,struct Node *node2);
Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int nA;
        cin>>nA;
        int nB;
        cin>>nB;
        struct Node* headA=NULL;
        struct Node* tempA = headA;
        for(int i=0;i<nA;i++)
        {
            int ele;
            cin>>ele;
            if(headA==NULL)
            {
                headA=tempA=newNode(ele);
            }else{
                tempA->next = newNode(ele);
				tempA=tempA->next;
            }
        }
        struct Node* headB=NULL;
        struct Node* tempB = headB;
        for(int i=0;i<nB;i++)
        {
            int ele;
            cin>>ele;
            if(headB==NULL)
            {
                headB=tempB=newNode(ele);
            }else{
                tempB->next = newNode(ele);
				tempB=tempB->next;
            }
        }
        struct Node* result = mergeResult(headA,headB);
        print(result);
        cout<<endl;
    }
}