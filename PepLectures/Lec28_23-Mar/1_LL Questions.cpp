#include <iostream>
#include <string>
#include <vector>

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
        Node* rdrLeft;
        Node* rdrRight;

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

        void dispRev(Node* node){
            if(node == NULL){
                return;
            }

            dispRev(node -> next);
            cout << node -> data << " ";
        }
    
        void rpr(Node* node){
            if(node == tail){
                return;
            }

            rpr(node -> next);
            node -> next -> next = node;
            node -> next = NULL;

            tail = node;
        }

        void rdr(Node* right, int floor){
            if(right == NULL){
                return;
            }

            rdr(right -> next, floor+1);

            if(floor >= size/2){
                int temp = rdrLeft -> data;
                rdrLeft -> data = right -> data;
                right -> data = temp;
            }

            rdrLeft = rdrLeft -> next;
        }

        void rdr2p(Node** left, Node* right, int floor){
            if(right == NULL){
                return;
            }

            rdr2p(left, right -> next, floor+1);

            Node* rleft = *left;

            if(floor >= size/2){
                int temp = right -> data;
                right -> data = rleft -> data;
                rleft -> data = temp;
            }

            *left = rleft -> next;
        }

        bool isPallindrome(Node** left, Node* right){
            if(right == NULL){
                return true;
            }

            bool rr = isPallindrome(left, right -> next);
            bool mr = rr == true && (*left) -> data == right -> data;

            *left = (*left) -> next;

            return mr;
        }

        void fold(Node** left, Node* right, int floor){
            if(right == NULL){
                return;
            }
            
            fold(left, right -> next, floor + 1);

            if(floor > size / 2){
                Node* temp = (*left) -> next;

                (*left) -> next = right;
                right -> next = temp;

                (*left) = temp;
            }

            else if(floor == size / 2){
                tail = right;
                tail -> next = NULL;
            }
        }

        void fold2(Node* right, int floor){
            if(right == NULL){
                return;
            }

            fold2(right -> next, floor + 1);

            if(floor > size/2){
                Node* temp = rdrLeft -> next;
                rdrLeft -> next = right;
                right -> next = temp;

                rdrLeft = temp;
            }
        }

        void unfold(Node* left){
            if(left -> next == NULL){
                head = tail = left;
                return;
            } else if(left -> next -> next == NULL){
                head = left;
                tail = left -> next;
                return;
            }

            unfold(left -> next -> next);
            Node* right = left -> next;

            left -> next = head;
            tail -> next = right;

            head = left;
            tail = right;

            tail -> next = NULL;
        }

        void kfl(Node* right, int k, int floor){
            if(right == NULL){
                return;
            }

            kfl(right -> next, k, floor + 1);

            if(floor + k == size){
                rdrRight = right;
                return;
            }
        }

        void kfl_wo_size(Node* right, int k, int* floor){
            if(right == NULL){
                (*floor) += 1;
                // cout << (*floor) << endl;
                return;
            }


            kfl_wo_size(right -> next, k, floor);

            if((*floor) == k){
                // cout << (*floor) << endl;
                rdrRight = right;
                (*floor) += 1;
                return;
            }

            else{
                (*floor) += 1;
                return;
            }
        }

        void addFirstNode(Node* nn){
            if(size == 0){
                head = tail = nn;
                size = 1;
            }
            
            else{
                nn->next = head;
                head = nn;
                size++;
            }
        }

        void addLastNode(Node* nn){
            if(size == 0){
                head = tail = nn;
                tail -> next = NULL;
                size = 1;
            }

            else{
                tail -> next = nn;
                tail = nn;
                size++;
            }
        }

        Node* removeFirstNode(){
            if(size == 0){
                return NULL;
            }

            else if(size == 1){
                Node* temp = head;
                head = tail = NULL;
                temp -> next = NULL;
                size = 0;
                return temp;
            }

            else{
                Node* temp = head;
                head = head -> next;
                size--;
                temp -> next = NULL;
                return temp;
            }
        }

        Node* midElement(Node* sp, Node* ep){
            Node* slow = sp;
            Node* fast = sp;

            while(fast != ep && fast->next != ep){
                slow = slow->next;
                fast = fast->next->next;
            }

            return slow;
        }

        LinkedList* mergeSort(Node* sp, Node* ep){
            if(sp == ep){
                LinkedList* baseLL = new LinkedList();
                baseLL->addLast(sp->data);
                return baseLL;
            }

            Node* mid = midElement(sp, ep);

            LinkedList* ll1 = mergeSort(sp, mid);
            LinkedList* ll2 = mergeSort(mid->next, ep);

            LinkedList* l = new LinkedList();

            l->mergeSortedLists(*ll1, *ll2);

            return l;
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
                cout << temp->data << " -> ";
                temp = temp->next;
            }

            cout << "N" << endl;
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

        void rdi(){
            for(int i = 0; i < size / 2; i++){
                Node* start = getNodeAt(i);
                Node* end = getNodeAt(size - i - 1);

                int temp = start -> data;
                start -> data = end -> data;
                end -> data = temp;
            }
        }

        void rpi_n2(){
            for(int i = size - 1; i >= 1; i--){
                Node* temp = getNodeAt(i);
                Node* tm1 = getNodeAt(i-1);

                temp -> next = tm1;
            }

            head -> next = NULL;

            Node* temp = tail;
            tail = head;
            head = temp;
        }

        void rpi_On(){
            if(size == 1 || size == 0){
                return;
            }
            if(size == 2){
                head -> next = NULL;
                tail -> next = head;

                Node* temp = head;
                head = tail;
                tail = temp;
                return;
            }
            
            Node* temp = head;
            Node* tp1 = getNodeAt(1);
            Node* tp2 = getNodeAt(2);

            for(; tp2 != NULL;){
                tp1 -> next = temp;
                temp = tp1;
                tp1 = tp2;
                tp2 = tp2 -> next;
            }

            head -> next = NULL;

            Node* t = head;
            head = tail;
            tail = t;
        }

        void rpi_correct(){
            if(size == 1 || size == 0){
                return;
            }

            if(size == 2){
                head -> next = NULL;
                tail -> next = head;

                Node* temp = head;
                head = tail;
                tail = temp;
                return;
            }

            Node* prev = NULL;
            Node* curr = head;
            Node* next = head -> next;

            while(curr != NULL){
                curr -> next = prev;
                prev = curr;
                curr = next;

                if(next != NULL)
                    next = next -> next;
            }

            Node* temp = head;
            head = tail;
            tail = temp;
        }

        void dispRev(){
            dispRev(head);
        }

        void rpr(){
            Node* temp = tail;
            rpr(head);
            head = temp;
        }

        void rdr(){
            rdrLeft = head;
            rdr(head, 0);
        }

        bool isPallindrome(){
            Node* left = head;
            Node* right = head;

            return isPallindrome(&left, right);
        }

        void fold(){
            Node* left = head;
            Node* right = head;

            fold(&left, right, 0);
        }

        void unfold(){
            Node* left = head;

            unfold(left);
        }

        void fold2(){
            rdrLeft = head;

            fold2(head, 0);

            tail = rdrLeft;
            tail -> next = NULL;
        }

        void rdr2p(){
            Node* left = head;
            Node* right = head;

            rdr2p(&left, right, 0);
        }

        void kfl(int k){
            rdrRight = head;
            kfl(head, k, 0);

            cout << rdrRight -> data << endl;
        }

        void kfl_wo_size(int k){
            int floor = 0;
            kfl_wo_size(head, k, &floor);

            cout << rdrRight -> data << endl;
        }

        void refresh(LinkedList* l){
            l -> head = NULL;
            l -> tail = NULL;
            l -> size = 0;

            return;
        }

        void kReverse(int k){
            LinkedList* prev = NULL;
            LinkedList* curr = new LinkedList();

            while(this -> size != 0){
                for(int i = 0; i < k && this -> size != 0; i++){
                    curr -> addFirstNode(this -> removeFirstNode());
                }

                if(prev == NULL){
                    prev = curr;
                    curr = new LinkedList(); // separating out prev and curr
                }

                else {
                    prev -> tail -> next = curr -> head;
                    prev -> tail = curr -> tail;
                    prev -> size += curr -> size;

                    refresh(curr);               
                }
            }

            this -> head = prev -> head;
            this -> tail = prev -> tail;
            this -> size = prev -> size;

            refresh(prev);
            delete prev;
        }

        void oddEven(){
            LinkedList* odd = new LinkedList();
            LinkedList* even = new LinkedList();

            while(this -> size != 0){
                if((head -> data) % 2 == 0){
                    Node* temp = this -> removeFirstNode();
                    even -> addLastNode(temp);
                    // delete temp;
                }
                else {
                    Node* temp = this -> removeFirstNode();
                    odd -> addLastNode(temp);
                    // delete temp;
                }
            }

            if(even -> size == 0){
                this -> head = odd -> head;
                this -> tail = odd -> tail;
                this -> size = odd -> size;
            }
            else if(odd -> size == 0){
                this -> head = even -> head;
                this -> tail = even -> tail;
                this -> size = even -> size;
            }
            else {
                this -> head = odd -> head;
                odd -> tail -> next = even -> head;
                this -> tail = even -> tail;
                this -> size = odd -> size + even -> size;
            }
            // odd -> display();
            // cout << even -> size << endl;

            refresh(odd);
            refresh(even);
            delete odd;
            delete even;
        }

        void removeDup(){
            LinkedList* l = new LinkedList();
            
            while(size != 0){
                Node* temp = this -> removeFirstNode();

                if(l -> size == 0 || l -> tail -> data != temp -> data){
                    l -> addLastNode(temp);
                }
                else
                {
                    delete temp;
                }            
            }

            this -> head = l -> head;
            this -> tail = l -> tail;
            this -> size = l -> size;

            refresh(l);
            delete l;
        }

        int midElement(){
            Node* slow = head;
            Node* fast = head;

            while(fast->next != NULL && fast->next->next != NULL){
                slow = slow->next;
                fast = fast->next->next;
            }

            return slow->data;
        }

        int midElementVariation(){
            Node* mid = midElement(head, tail);

            return mid->data;
        }

        int kthFromLast(int k){
            Node* slow = head;
            Node* fast = head;

            // Make a difference of k between slow and fast
            for(int i = 0; i < k-1; i++){
                fast = fast->next;
            }

            while(fast->next != NULL){
                slow = slow->next;
                fast = fast->next;
            }

            return slow->data;
        }

        // LinkedList multiply(LinkedList l2){
        //     LinkedList l;

        //     this->head
        // }

        int addLinkedList(LinkedList& ll1, LinkedList& ll2, Node* h1, Node* h2, int s1, int s2){
            if(h1 == NULL && h2 == NULL){
                return 0;
            }
            
            if(s1 > s2){
                addLinkedList(ll1, ll2, h1->next, h2, s1-1, s2);
            }
            else if(s1 < s2){
                addLinkedList(ll1, ll2, h1, h2->next, s1, s2-1);
            }
            else{
                addLinkedList(ll1, ll2, h1->next, h2->next, s1-1, s2-1);
            }

            int sum = h1->data + h2->data;
            int data = sum % 10;
            int carry = sum / 10;

            this->addFirst(data);

            return carry;
        }

        void mergeSortedLists(LinkedList& ll1, LinkedList& ll2){
            Node* t1 = ll1.head;
            Node* t2 = ll2.head;

            while(t1 != NULL && t2 != NULL){
                if(t1->data <= t2->data){
                    this->addLast(t1->data);
                    t1 = t1->next;
                }

                else{
                    this->addLast(t2->data);
                    t2 = t2->next;
                }
            }

            if(t1 == NULL){
                while(t2 != NULL){
                    this->addLast(t2->data);
                    t2 = t2->next;
                }
            }

            if(t2 == NULL){
                while(t1 != NULL){
                    this->addLast(t1->data);
                    t1 = t1->next;
                }
            }
        }

        LinkedList* mergeSort(){
            LinkedList* sl = mergeSort(head, tail);
            return sl;
        }
};

int main(int argc, char** argv){
    LinkedList* ll2 = new LinkedList();

    ll2->addLast(10);
    ll2->addLast(20);
    ll2->addLast(30);
    ll2->addLast(40);
    ll2->addLast(50);
    ll2->addLast(60);
    ll2->addLast(70);
    ll2->addLast(80);
    ll2->addLast(90);
    ll2->addLast(100);

    ll2->display();

    ll2->oddEven();
    ll2->display();


    // cout << ll2->midElement() << endl;
    // cout << ll2->midElementVariation() << endl;
    // cout << ll2->kthFromLast(7) << endl;

    // LinkedList* l1 = new LinkedList();
    // LinkedList* l2 = new LinkedList();
    // LinkedList* l3 = new LinkedList();


    // l2->addLast(4);
    // l2->addLast(5);
    // l2->display();

    // l3->addLast(1);
    // l3->addLast(2);
    // l3->addLast(3);

    // l3->display();
 
    // // l1 = l2->multiply(l3);

    // l1->mergeSortedLists(l2, l3);

    // l1->display();


    // LinkedList* ll2 = new LinkedList();
    // LinkedList* ll1 = new LinkedList();

    // ll2->addLast(100);
    // ll2->addLast(1100);
    // ll2->addLast(40);
    // ll2->addLast(200);
    // ll2->addLast(90);
    // ll2->addLast(10);

    // ll1 = ll2->mergeSort();

    // ll1->display();

    // LinkedList l1, l2;

    // l1.addLast(1);
    // l1.addLast(2);
    // l1.addLast(3);

    // l2.addLast(4);
    // l2.addLast(5);

    // LinkedList l;

    // l.addLinkedList(l1, l2, )
    return 0;
}
