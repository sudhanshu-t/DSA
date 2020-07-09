#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

Node* head;
Node* tail;
int size;

void insert(int data) {
    Node* nn = new Node(data);
    if (head == NULL) {
        head = nn;
        tail = nn;
    } else {
        tail->next = nn;
        tail = nn;
    }
    size++;
}

Node* search_Node(Node* head, int k) {
    while (head != NULL) {
        if (head->data == k) {
            return head;
        }
        head = head->next;
    }
    return NULL;
}

void display(Node* head) {
    for (Node* node = head; node != NULL; node = node->next) {
    cout<<node->data<<" ";
    }
}

// ---------------------------------------------------------------
// This is a functional problem. Only this function has to be written.
// This function returns the count of nodes in loop in the list.

int countNodesInLoop(Node* head) {
    Node* slow = head;
    Node* fast = head;

    while(slow != NULL && fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast){
            break;
        }
    }

    int count = 0;
    if(slow == fast){
        Node* temp = slow;
        count = 1;

        while(temp->next != slow){
            temp = temp->next;
            count++;
        }
    }

    return count;
}

// ------------------------------------------------------------------

int main(int argc, char** argv) {
    int n1;
    cin>>n1;

    for (int i = 0; i < n1; i++) {
        int a;
        cin>>a;
        insert(a);
    }

    Node* temp = NULL;
    Node* te = NULL;
    int c;
    cin>>c;
    if (c > 0) {
        temp = head;
        te = head;
        while (te->next != NULL) 
        te = te->next;
        while (c-- > 0) 
        temp = temp->next;
        te->next = temp;

    }
    cout<<countNodesInLoop(head);

}