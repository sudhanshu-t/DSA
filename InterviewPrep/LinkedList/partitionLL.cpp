#include<iostream>
using namespace std;

// Class declaration for a Node of the Linked List
class Node {
    public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

Node* head1;

/*
* Input Parameters: head: head of the linked list in which a new node is to
* be inserted. data: the data value of the node which is to be inserted.
* 
* Return Value: head of the linked list in which the node is inserted
*/
Node* insert(Node* head, int data) {

    if (head == NULL) {
        Node* nn = new Node(data);
        return nn;
    }

    head->next = insert(head->next, data);
    return head;
}

void display(Node* head) {
    for (Node* node = head; node != NULL; node = node->next) {
        cout<<node->data<<" ";
    }
}

Node* removeFirst(Node*& n){
    if(n->next == NULL){
        Node* temp = n;
        n = NULL;
        delete n;
        return temp;
    }

    Node* temp = n;
    n = n->next;
    temp->next = NULL;
    return temp;
}

void addLast(Node*& head, Node*& tail, Node* rem){
    if(head == NULL){
        head = tail = rem;
        tail->next = NULL;
        return;
    }

    tail->next = rem;
    tail = rem;
}

// -----------------------------------------------------
// This is a functional problem. Only this function has to be written.
// This takes as input the head of the linked list and x.
// It should return the head of the modified list.
Node* partition(Node* n, int x) {
// write your code here
    Node* lval = NULL;
    Node* ltail = NULL;
    Node* gval = NULL;
    Node* gtail = NULL;

    while(n != NULL){
        Node* rem = removeFirst(n);
        // cout << "Removed " << rem->data << endl;
        if(rem->data < x){
            addLast(lval, ltail, rem);
            // cout << "Lower " << ltail->data << endl;
        } else {
            addLast(gval, gtail, rem);
            // cout << "Greater " << gtail->data << endl;
        }
        // cout << "n is " << n->data << endl;
    }

    // Node* temp = lval;
    // while(temp != NULL){
        // cout << temp->data << " ";
        // temp = temp->next;
    // }
    // cout << endl;

    // temp = gval;
    // while(temp != NULL){
        // cout << temp->data << " ";
        // temp = temp->next;
    // }
    // cout << endl;

    if(lval != NULL && gval != NULL){
        // cout << lval->data << endl;
        ltail->next = gval;
        n = lval;
    } else if(lval != NULL){
        n = lval;
    } else {
        n = gval;
    }

    return n;
}

// -----------------------------------------------------

int main(int argc, char** argv) {
    int n1;
    cin>>n1;

    for (int i = 0; i < n1; i++) {
        int a;
        cin>>a;
        head1 = insert(head1, a);
    }

    int x;
    cin>>x;
    
    head1 = partition(head1, x);
    display(head1);

}