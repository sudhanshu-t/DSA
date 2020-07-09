#include <iostream>
#include <vector>
#include <string>

using namespace std;

class LinkedList{
    private:
    class Node{
        public:
        int data;
        Node* next;
    };

    int size;
    Node* head;
    Node* tail;
    Node* tempLeft;
    Node* tempright;

    void rdr(Node* right, int floor){
        if(right == NULL){
            return;
        }

        rdr(right->next, floor+1);

        if(floor >= size/2){
            int temp = tempLeft->data;
            tempLeft->data = right->data;
            right->data = temp;
        }
        
        tempLeft = tempLeft->next;
    }

    void rdrp2p(Node** left, Node* right, int floor){
        if(right == NULL){
            return;
        }

        rdrp2p(left, right->next, floor+1);

        if(floor >= size/2){
            Node* realL = (*left);

            int temp = realL->data;
            realL->data = right->data;
            right->data = temp;

            (*left) = realL->next;
        }
    }

    void rprp2p(Node** left, Node* right, int floor){
        if(right == NULL){
            return;
        }

        rprp2p(left, right->next, floor+1);

        if(floor >= size/2){
            Node*
        }
    }

    public:

    LinkedList(){
        this->size = 0;
        this->head = NULL;
        this->tail = NULL;
    }

    ~LinkedList(){
        Node* temp = head;

        while(temp != NULL){
            Node* r = temp;
            temp = temp->next;
            delete r;
        }
    }

    void handleAddSize0(int data){
        Node* nn = new Node();

        head = tail = nn;
        head->data = data;
        tail->next = NULL;

        size = 1;
    }

    void handleRemoveSize1(){
        head = tail = NULL;
        size = 0;

        delete head;
    }

    void addLast(int data){
        if(size == 0){
            handleAddSize0(data);
        }

        else {
            Node* nn = new Node();

            nn->data = data;

            tail->next = nn;
            tail = nn;
            tail->next = NULL;

            size++;
        }
    }

    void addFirst(int data){
        if(size == 0){
            handleAddSize0(data);
        }

        else {
            Node* nn= new Node();

            nn->data = data;
            nn->next = head;

            head = nn;

            size++;
        }
    }

    void display(){
        Node* temp = head;

        while(temp){
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }

    int removeFirst(){
        if(size == 1){
            handleRemoveSize1();
        }

        else {
            Node* r = head;

            head = head->next;
            size--;

            int data = r->data;
            delete r;
            return data;
        }
    }

    Node* getNodeAt(int n){
        Node* temp = head;

        for(int i = 0; i < n; i++){
            temp = temp->next;
        }

        return temp;
    }

    void addAt(int data, int i){
        if(size == 0){
            handleAddSize0(data);
        }

        else {
            Node* nn = new Node();

            nn->data = data;

            Node* nm1 = getNodeAt(i-1);
            Node* np1 = getNodeAt(i);

            nm1->next = nn;
            nn->next = np1;

            size++;
        }
    }

    int removeLast(){
        if(size == 1){
            handleRemoveSize1();
        }

        else {
            Node* tm1 = getNodeAt(size-2);

            int data = tail->data;

            tm1->next = NULL;

            delete tail;

            tail = tm1;

            size--;

            return data;
        }
    }

    int removeAt(int i){
        if(size == 1){
            handleRemoveSize1();
        }

        else {
            Node* nm1 = getNodeAt(i-1);
            Node* np1 = getNodeAt(i+1);

            Node* n = getNodeAt(i);

            int data = n->data;
            delete n;

            nm1->next = np1;
            size--;

            return data;
        }
    }

    void rdi(){
        Node* left = head;
        Node* right = tail;

        for(int i = 0; i < size/2; i++){
            int temp = left->data;
            left->data = right->data;
            right->data = temp;

            left = left->next;
            right = getNodeAt(size-i-2);
        }
    }

    void rpi(){
        Node* prev = NULL;
        Node* curr = head;
        Node* next = curr->next;

        while(curr){
            curr->next = prev;

            prev = curr;
            curr = next;

            if(next != NULL)
                next = next->next;
        }

        Node* temp = head;
        head = tail;
        tail = temp;
    }

    void rdr(){
        tempLeft = head;
        rdr(head, 0);

        // Node* temp = head;
        // head = tail;
        // tail = temp;
    }

    void rdrp2p(){
        Node* left = head;
        Node* right = head;

        rdrp2p(&left, right, 0);
    }

    void rprp2p(){
        Node* left = head;
        Node* right = head;

        rprp2p(&left, right, 0);

        Node* temp = head;
        headd = tail;
        tail = temp;
    }
};

int main(int argc, char** argv){
    LinkedList l;

    l.addLast(10);
    l.addLast(20);
    l.addLast(30);
    l.addLast(40);
    l.addLast(50);
    l.addLast(60);
    l.addLast(70);
    l.addLast(80);
    l.addLast(90);

    // l.display();
    // cout << l.removeFirst() << endl;
    // l.display();
    // cout << l.removeLast() << endl;
    // l.display();
    // cout << l.removeAt(3) << endl;
    // l.display();
    // l.addAt(34, 3);
    // l.display();

    // l.rdi();
    // l.display();
    // l.rpi();
    l.display();
    l.rdr();
    l.display();
    l.rdrp2p();
    l.display();
}