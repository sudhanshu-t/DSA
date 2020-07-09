#include <iostream>

using namespace std;
// -----------------------------------------------------
// This is a functional problem. Only this function has to be written.
// This function takes as input the head of the linked list and key.
// It should return the head of the modified list.
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

static Node* head1;

static Node* head2;

static Node* head3;

/*
* Input Parameters: head: head of the linked list in which a new node is to
* be inserted. data: the data value of the node which is to be inserted.
* 
* Return Value: head of the linked list in which the node is inserted
*/
Node* insert(Node* head, int data) {

    if (head == NULL) {
        return new Node(data);
    }

    head->next = insert(head->next, data);
    
    return head;
}

/*
* Input Parameters: head: head of the linked list in which is to be
* displayed.
* 
* Return Value: null
*/
void display(Node* head) {
    
    for (Node* node = head; node != NULL; node = node->next) {
        cout << node->data << " ";
    }
    
    cout << endl;
}

Node* rpi(Node* head){
    Node* prev = NULL;
    Node* curr = head;
    Node* next = curr->next;

    // cout << curr->data << endl;

    while(curr != NULL){
        curr->next = prev;
        // cout << curr->data << " Points to " << prev->data << endl;
        prev = curr;
        curr = next;

        if(next != NULL)
            next = next->next;

        // cout << prev->data << " " << curr->data << " " << next->data << endl;
    }

    return prev;
}

Node* func(Node* head, int key) {
    // write your code here
    if(head->next == NULL)
    {   if(head->data == key){
            delete head;
            return NULL;
        } else {
            return head;
        }
    }

    Node* nh = rpi(head);

    Node* curr = nh;
    Node* next = nh->next;

    // display(curr);

    if(curr->data == key){
        Node* temp = curr;
        curr = curr->next;
        // cout << temp->data << " " << head->data << endl;

        temp->next = NULL;
        delete temp;
        head = rpi(curr);
        
        return head;
    }

    while(next != NULL && next->data != key){
        curr = next;
        next = next->next;        
    }

    if(next == NULL){
        // display(head);
        return rpi(nh);
    }

    curr->next = next->next;
    next->next = NULL;

    delete next;

    head = rpi(nh);
}

// -----------------------------------------------------

int main(int argc, char** argv) {
    int n1; cin >> n1;
    int a1; cin >> a1;
    head1 = insert(head1, a1);

    int a;

    for (int i = 1; i < n1; i++) {
        cin >> a;
        head1 = insert(head1, a);
    }

    int k;
    cin >> k;
    head1 = func(head1, k);
    display(head1);
}