#include <iostream>
using namespace std;

class Node {
    public:
    char data;
    Node* next;

    Node(char data, Node* next) {
        this->data = data;
        this->next = next;
    }
};

Node* head = NULL;
Node* tail = NULL;
int size = 0;
 
void insert(char data) {
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
 
void display() {
    for (Node* node = head; node != NULL; node = node->next) {
        cout << node->data << " ";
    }
}

void addLast(Node*& head, Node*& tail, char d){
    if(head == NULL){
        head = new Node(d, NULL);
        tail = head;
        // cout << d << " added in " << node->data << endl;
    } else {
        Node* nn = new Node(d, NULL);
        tail->next = nn;
        tail = nn;
    }
}

//---------------------------------------------------------------
//This is a functional problem. Only this function has to be written.
// This function should return the head of node after sorting.
Node* arcv(Node* head) {
    Node* vh = NULL;
    Node* vt = NULL;
    Node* ch = NULL;
    Node* ct = NULL;

    while(head){
        Node* nn = new Node(head->data, NULL);
        
        if(head->data == 'a' ||
           head->data == 'e' ||
           head->data == 'i' ||
           head->data == 'o' ||
           head->data == 'u'){
            //    cout << "V" << endl;
               addLast(vh, vt, head->data);
        } else {
            // cout << "c" << endl;
            addLast(ch, ct, head->data);
        }

        head = head->next;
    }

    // cout << vh->data << endl;
    // cout << ch->data << endl;

    if(vh == NULL){
        Node* temp = ch;

        // while(temp->next){
        //     temp = temp->next;
        // }

        // tail = temp;
        tail = ct;
        return ch;
    } else if(ch == NULL){
        Node* temp = vh;

        // while(temp->next){
        //     temp = temp->next;
        // }

        // tail = temp;
        tail = vt;
        return vh;
    } else {
        vt->next = ch;

        tail = ct;
        return vh;
    }
}

int main(int argc, char** argv) {       
    int n;
    cin>>n; 

    char h;
    cin>>h;
    insert(h);

    for (int i = 1; i < n; i++) {
        char ch;
        cin >> ch;
        insert(ch);
    }
    
    // cout << head->data << endl;

    head = arcv(head);
    display();

    // cout << head->data << endl;
}


     
 