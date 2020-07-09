#include <iostream>
#include <string>

using namespace std;

class Node {
    public:
    int coeff;
    int pow;
    Node* next;

    Node(int a, int b) {
        coeff = a;
        pow = b;
        next = NULL;
    }

};

void addLast(Node*& head, Node*& tail, int c, int p){
    if(head == NULL){
        head = new Node(c, p);
        tail = head;
        // cout << "Node " << c << " " << p << " formed" << endl;
        return;
    }
    // cout << "Node " << c << " " << p << " formed" << endl;
    Node* nn = new Node(c, p);
    tail->next = nn;
    tail = nn;
    return;
}

// -----------------------------------------------------
// This is a functional problem. Only this function has to be written.
// This function takes as input the head of two linked lists representing
// two polynomial numbers.
// Print the polynomial formed by adding both LL in the function itself.
void addPolynomial(Node*& poly1, Node* poly2) {
    // write your code here
    // Print the polynomial formed by adding both LL in the function itself.

    Node* h1 = NULL;
    Node* t1 = NULL;
    Node* temp1 = poly1;
    Node* temp2 = poly2;

    while(temp1 != NULL && temp2 != NULL){
        if(temp1->pow > temp2->pow){
            addLast(h1, t1, temp1->coeff, temp1->pow);
            temp1 = temp1->next;
        } else if(temp1->pow < temp2->pow){
            addLast(h1, t1, temp2->coeff, temp2->pow);
            temp2 = temp2->next;
        } else {
            int c = temp1->coeff + temp2->coeff;
            addLast(h1, t1, c, temp1->pow);
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
    }

    if(temp1 != NULL){
        while(temp1){
            addLast(h1, t1, temp1->coeff, temp1->pow);
            temp1 = temp1->next;
        }
    } else if(temp2 != NULL){
        while(temp2){
            addLast(h1, t1, temp2->coeff, temp2->pow);
            temp2 = temp2->next;
        }
    }

    poly1 = h1;
}
// -----------------------------------------------------

Node* head;

Node* head2;

Node* head3;


/*
* Input Parameters: head: head of the linked list in which a new node is to
* be inserted. data: the data value of the node which is to be inserted.
* 
* Return Value: head of the linked list in which the node is inserted
*/
Node* insert(Node* head, int a, int b) {

    if (head == NULL) {
        Node* nn = new Node(a, b);
        return nn;
    }

    head->next = insert(head->next, a, b);

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
        if(node == head)
            cout << to_string(node->coeff) + "x^" + to_string(node->pow);

        else
            cout << " + " << to_string(node->coeff) + "x^" + to_string(node->pow);
    }
}

int main(int argc, char** argv) {
    int n; cin >> n;
    int a1; cin >> a1;
    int b1; cin >> b1;
    head = insert(head, a1, b1);

    for (int i = 1; i < n; i++) {
        int a; cin >> a;
        int b; cin >> b;
        head = insert(head, a, b);
    }

    // display(head);

    int n2; cin >> n2;
    int a2; cin >> a2;
    int b2; cin >> b2;
    head2 = insert(head2, a2, b2);

    for (int i = 1; i < n2; i++) {
        int a; cin >> a;
        int b; cin >> b;
        head2 = insert(head2, a, b);
    }

    // display(head2);

    addPolynomial(head, head2);

    display(head);
}
