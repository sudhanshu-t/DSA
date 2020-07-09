#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data, Node* next) {
        this->data = data;
        this->next = next;
    }

};

Node* head;
Node* tail;
int size;

void insert(int data) {
    Node* nn = new Node(data, NULL);
    if (head == NULL) {
        head = nn;
        tail = nn;
    } else {
        tail->next = nn;
        tail = nn;
    }
    size++;
}

void display(Node* n) {
    for (Node* node = n; node != NULL; node = node->next) {
        cout << node->data << " ";
    }
}

// ---------------------------------------------------------
// This is a functional problem. Only this function has to be written.
// return true if linkedlist is circular else return false
bool checkcircular(Node* n) {
    Node* temp = n;

    while(temp->next != NULL && temp->next != n){
        temp = temp->next;
    }

    if(temp->next == NULL){
        return false;
    } else {
        return true;
    }
}

int main(int argc, char** argv) {
    int n;
    cin >> n;
    int s;
    cin >> s;
    int a1;
    cin >> a1;
    insert(a1);

    int a;
    for (int i = 1; i < n; i++) {
        cin >> a;
        insert(a);
    }
    if(s==1&&n>0){
        tail->next=head;
    }

    bool isCircular = checkcircular(head);

    if(isCircular)
        cout << "true" << endl;
    else
        cout << "false" << endl;
}