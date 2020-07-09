#include <iostream>

using namespace std;

class LinkedList{
    private:
        class Node{
            public:
                int data;
                Node* next;
        };

        Node* head;
        Node* tail;
        int size;

        void handleAddWhenSizeIs0(int data){
            Node* nn = new Node();

            nn->data = data;
            nn->next = NULL;

            head = tail = nn;
            size = 1;
        }

        int handleRemoveWhenSizeIsOne(){
            int data = head -> data;

            delete head;

            head = tail = NULL;
            size = 0;

            return data;
        }

        Node* getNodeAt(int idx){
            if(idx < 0 || idx >= size){
                return NULL;
            }

            Node* nn = head;

            for(int i = 0; i < idx; i++){
                nn = nn -> next;
            }

            return nn;
        }

    public:
        // Constructor
        LinkedList(){
            head = tail = NULL;
            size = 0;    
        }

        // Destructor
        ~LinkedList(){
            Node* temp = head;

            for(; temp != NULL;){
                Node* r = temp;
                temp = temp->next;
                delete r;
            }
        }

        void addLast(int data){
            if(size == 0){
                handleAddWhenSizeIs0(data);
            }

            else{
                Node* nn = new Node();

                nn->data = data;
                nn->next = NULL;

                tail->next = nn;
                tail = nn;

                size++;
            }
        }

        void addFirst(int d){
            if(size == 0){
                handleAddWhenSizeIs0(d);
            }
            
            Node* nn = new Node();

            nn->next = head;
            nn->data = d;

            head = nn;
            size++;
        }

        void addAt(int data, int idx){
            if(size == 0){
                handleAddWhenSizeIs0(data);
            }

            if(idx < 0 || idx >= size){
                cout << "Invalid index" << endl;
                return;
            }

            Node* n = new Node();
            n->data = data;
            
            Node* nm1 = getNodeAt(idx-1);
            Node* np1 = getNodeAt(idx);

            nm1->next = n;
            n->next = np1;

            size++;
        }

        int getFirst(){
            return head->data;
        }

        int getLast(){
            return tail->data;
        }

        int getAt(int i){
            Node* nn = getNodeAt(i); // No need to delete nn since it will delete the ith node in LL. It is just a reference.

            return nn -> data;
        }

        int removeFirst(){
            if(size == 1){
                return handleRemoveWhenSizeIsOne();
            }
            
            int data = head -> data;
            
            Node* r = head;
            head = head -> next;
            delete r;

            size--;
            return data;
        }

        int removeLast(){
            if(size == 1){
                return handleRemoveWhenSizeIsOne();
            }

            Node* l = getNodeAt(size-1);
            Node* sl = getNodeAt(size-2);

            int data = l->data;
            tail = sl;
            size--;
            delete l;

            return data;
        }

        int removeAt(int idx){
            if(size == 1){
                return handleRemoveWhenSizeIsOne();
            }

            Node* n = getNodeAt(idx);
            Node* nm1 = getNodeAt(idx-1);
            Node* np1 = n->next;

            nm1->next = np1;

            int data = n->data;
            size--;

            delete n;

            return data;
        }

        void display(){
            Node* temp = head;

            for(int i = 0; i < size; i++){
                cout << temp->data << " ";
                temp = temp->next;
            }

            cout << endl;
        }

        int getSize(){
            return size;
        }

        bool isEmpty(){
            if(size == 0){
                return true;
            }

            return false;
        }
};

int main(int argc, char** argv){
    // LinkedList ll1;
    // ll1.addLast(10);
    // ll1.addLast(20);
    // ll1.addLast(30);
    // ll1.addLast(40);
    // ll1.addLast(50);
    // ll1.display();

   
    // ll2->addAt(35, 3);
    // cout << ll2->removeAt(3) << endl;
    // cout << ll2->removeLast() << endl;
    // cout << ll2->getAt(3) << endl;
    // ll2->removeFirst();
    // (*ll2).display();

    // cout << ll2->getSize() << endl;
    // cout << ll2->isEmpty() << endl;
    // cout << ll2 -> getFirst() << endl;
    // cout << ll2 -> getLast() << endl;

    LinkedList* ll2 = new LinkedList();

    ll2->addLast(10);
    ll2->addLast(20);
    ll2->addLast(30);
    ll2->addLast(40);
    ll2->addLast(50);
}