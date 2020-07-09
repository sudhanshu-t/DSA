#include <iostream>
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
    Node* tempL;
    Node* tempR;

    void Add_SizeZero(int data){
        Node* nn = new Node();

        nn->data = data;

        head = nn;
        tail = nn;

        tail->next = NULL;

        size = 1;
    }

    int Remove_SizeOne(){
        int rv = head->data;

        delete head;

        head = tail = NULL;
        size = 0;
        
        return rv;
    }

    Node* getNodeAt(int i){
        Node* temp = head;

        for(int idx = 0; idx < i; idx++){
            temp = temp->next;
        }

        return temp;
    }

    void dispRev(Node* head){
        if(!head){
            return;
        }
        
        dispRev(head->next);
        cout << head->data << " ";
    }

    void rdr(Node* right, int floor){
        if(!right){
            return;
        }

        rdr(right->next, floor + 1);

        if(floor >= size / 2){
            int temp = right->data;
            right->data = tempL->data;
            tempL->data = temp;

            tempL = tempL->next;
        }
    }

    void rdr2p(Node** left, Node* right, int floor){
        if(!right){
            return;
        }

        rdr2p(left, right->next, floor+1);

        if(floor >= size / 2){
            int temp = (*left)->data;
            (*left)->data = right->data;
            right->data = temp;

            (*left) = (*left)->next;
        }
    }

    void rpr(Node* node){
        if(node == tail){
            return;
        }

        rpr(node->next);
        node->next->next = node;
        node->next = NULL;
        tail = node;
    }

    bool isPallin(Node** left, Node* right){
        if(!right){
            return true;
        }

        bool rr = isPallin(left, right->next);
        bool mr = (rr == true) && (*left)->data == right->data;

        (*left) = (*left)->next;
        return mr;
    }

    void fold(Node** left, Node* right, int floor){
        if(!right){
            return;
        }

        fold(left, right->next, floor + 1);

        if(floor > size / 2){
            Node* temp = (*left)->next;
            (*left)->next = right;
            right->next = temp;

            (*left) = temp;
        } else if(floor == size / 2){
            tail = right;
            right->next = NULL;
        }
    }

    // void unfold(Node* right, int floor){
    //     if(!right){
    //         return;
    //     }

    //     unfold(right->next, floor + 1);

    //     cout << floor << endl;
    //     if(floor == size - 1){
    //         tail = right;
    //     }


    //     if(floor > size / 2){
    //         tempL->next = right->next;
    //         right->next = tempR;
    //         tempR = right;
    //         tempL = tempL->next;
    //     } else if(floor == size / 2) {
    //         right->next = tempR;
    //     }
    // }

    void unfold(Node* left){
        if(left->next == NULL){
            head = tail = left;
            return;
        }

        if(left->next->next == NULL){
            head = left;
            tail = left->next;
            return;
        }

        unfold(left->next->next);

        Node* right = left->next;

        left->next = head;
        tail->next = right;

        head = left;
        tail = right;

        tail->next = NULL;
    }

    int kfl(Node* node, int floor, int k){
        if(floor == size - k){
            return node->data;
        }
        
        return kfl(node->next, floor+1, k);
    }

    void kfl_wo_size(Node* node, int* floor, int k){
        if(node == NULL){
            (*floor)++;
            return;
        }

        kfl_wo_size(node->next, floor, k);

        if((*floor) == k){
            (*floor) = node->data;
        } else if((*floor) < k){
            (*floor)++;
        }
    }

    Node* removeFirstNode(){
        if(size == 1){
            Node* temp = head;

            head = tail = NULL;
            size = 0;

            return temp;
        } else {
            Node* temp = head;

            head = head->next;
            temp->next = NULL;

            size--;

            return temp;
        }
    }

    void addFirstNode(Node* nn){
        if(size == 0){
            head = tail = nn;
            size = 1;

            tail->next = NULL;
        } else {
            nn->next = head;

            head = nn;
            size++;
        }
    }

    void addLastNode(Node* nn){
        if(size == 0){
            head = tail = nn;
            size = 1;

            tail->next = NULL;
            
            return;
        } else {
            tail->next = nn;
            nn->next = NULL;
            tail = nn;
            size++;
        }
    }

    void refresh(LinkedList* ll){
        ll->head = ll->tail = NULL;
        ll->size = 0;
    }

public:
    LinkedList(){
        head = tail = NULL;
        size = 0;
    }

    ~LinkedList(){
        // Node* temp = head;
        // for(int i = 0; i < size; i++){
        //     head = head->next;
        //     delete temp;
        //     temp = head;
        // }

        Node* temp = head;

        for(; temp != NULL;){
            Node* r = temp;
            temp = temp->next;
            delete r;
        }
    }

    void addLast(int data){
        if(size == 0){
            Add_SizeZero(data);
        } else {
            Node* nn = new Node();

            nn->data = data;
            nn->next = NULL;
            
            tail->next = nn;
            tail = nn;

            size++;
        }
    }

    void addFirst(int data){
        if(size == 0){
            Add_SizeZero(data);
        } else {
            Node* nn = new Node();

            nn->data = data;
            nn->next = head;

            head = nn;

            size++;
        }
    }

    void addAt(int i, int d){
        if(size == 0){
            Add_SizeZero(d);
        } else {
            Node* nn = new Node();
            nn->data = d;

            Node* np1 = getNodeAt(i);
            Node* nm1 = getNodeAt(i-1);

            nm1->next = nn;
            nn->next = np1;

            size++;
        }
    }

    int getLast(){
        if(size == 0){
            return -1;
        } else {
            return tail->data;
        }
    }

    int getFirst(){
        if(size == 0){
            return -1;
        } else {
            return head->data;
        }
    }

    int getAt(int i){
        Node* n = getNodeAt(i);
        return n->data;
    }

    int removeLast(){
        if(size == 1){
            return Remove_SizeOne();
        } else {
            int rv = tail->data;

            Node* tm1 = getNodeAt(size - 2);
            Node* temp = tail;

            tail = tm1;
            tm1->next = NULL;

            delete temp;
            size--;

            return rv;
        }
    }

    int removeFirst(){
        if(size == 1){
            return Remove_SizeOne();
        } else {
            int rv = head->data;

            Node* temp = head;
            head = head->next;

            delete temp;

            size--;
            return rv;
        }
    }

    int removeAt(int i){
        if(size == 1){
            return Remove_SizeOne();
        } else {
            Node* nm1 = getNodeAt(i-1);
            Node* np1 = getNodeAt(i+1);

            Node* temp = getNodeAt(i);
            int rv = temp->data;

            nm1->next = np1;

            delete temp;
            size--;

            return rv;
        }
    }

    void display(){
        Node* temp = head;

        cout << temp->data;
        temp = temp->next;
        for(int i = 1; i < size; i++){
            cout << " ~ " << temp->data;
            temp = temp->next;
        }

        cout << endl;
    }

    int getSize(){
        return size;
    }

    bool isEmpty(){
        return size == 0;
    }

    void rdi(){
        for(int i = 0; i < size / 2; i++){
            Node* left = getNodeAt(i);
            Node* right = getNodeAt(size - i - 1);

            int temp = left->data;
            left->data = right->data;
            right->data = temp;
        }
    }

    void rpi(){
        if(size == 1 || size == 0){
            return;
        }
        
        if(size == 2){
            Node* temp = head;
            head = tail;
            tail = temp;

            head->next = tail;
            tail->next = NULL;

            return;
        }

        Node* prev = NULL;
        Node* curr = head;
        Node* next = head->next;

        // tail = curr;

        while(curr){
            curr->next = prev;
            prev = curr;
            curr = next;

            if(next)
                next = next->next;
        }

        // head = prev;
        Node* temp = head;
        head = tail;
        tail = temp;
    }

    void dispRev(){
        dispRev(head);
    }

    void rdr(){
        tempL = head;
        rdr(head, 0);
    }

    void rdr2p(){
        Node* left = head;

        rdr2p(&left, head, 0);
    }

    void rpr(){
        Node* temp = tail;

        rpr(head);

        head = temp;
    }

    bool isPallin(){
        Node* left = head;
        Node* right = head;
        return isPallin(&left, right);
    }

    void fold(){
        Node* left = head;
        fold(&left, head, 0);
    }

    // void unfold(){
    //     tempR = NULL;
    //     tempL = head;

    //     unfold(head, 0);
    // }

    void unfold(){
        unfold(head);
    }

    int kfl(int k){
        return kfl(head, 0, k);
    }

    int kfl_wo_size(int k){
        int floor = 0;

        kfl_wo_size(head, &floor, k);

        return (floor);
    }

    void kReverse(int k){
        LinkedList* prev = new LinkedList();
        LinkedList* curr = new LinkedList();

        while(this->size != 0){
            for(int i = 0; i < k && this->size != 0; i++){
                Node* rem = this->removeFirstNode();
                prev->addFirstNode(rem);
            }

            if(curr->size == 0){
                curr->head = prev->head;
                curr->tail = prev->tail;
                curr->size = prev->size;
            } else {
                curr->tail->next = prev->head;
                curr->tail = prev->tail;
                curr->tail->next = NULL;
                curr->size += prev->size;
            }

            refresh(prev);
        }

        this->head = curr->head;
        this->tail = curr->tail;
        this->size = curr->size;

        refresh(curr);
        delete curr;
        delete prev;
    }

    void oddEven(){
        LinkedList* odd = new LinkedList();
        LinkedList* even = new LinkedList();

        while(this->size != 0){
            if(head->data % 2 == 0){
                even->addLastNode(this->removeFirstNode());
            } else {
                odd->addLastNode(this->removeFirstNode());
            }
        }

        if(even->size == 0 || odd->size == 0){
            delete even;
            delete odd;
        } else {
            LinkedList* temp = this;
            odd->tail->next = even->head;
            this->head = odd->head;
            this->tail = even->tail;
            this->size = odd->size + even->size;

            // delete temp;
        }
    }

    void removeDupSorted(){
        LinkedList* nll = new LinkedList();

        while(size != 0){
            Node* nn = this->removeFirstNode();

            if(nll->size == 0){
                nll->addLastNode(nn);
            } else {
                if(nll->tail->data != nn->data){
                    nll->addLastNode(nn);
                }
            }
        }

        this->head = nll->head;
        this->tail = nll->tail;
        this->size = nll->size;

        refresh(nll);
        delete nll;
    }

    int midElement(){
        Node* slow = head;
        Node* fast = head;

        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow->data;
    }

    int kFromLast_slowFast(int k){
        Node* slow = head;
        Node* fast = head;

        for(int i = 0; i < k-1; i++){
            fast = fast->next;
        }

        while(fast->next){
            slow = slow->next;
            fast = fast->next;
        }

        return slow->data;
    }
};

int main(int argc, char** argv){
    LinkedList ll;

    // Add Last
    ll.addLast(10);
    ll.addLast(20);
    ll.addLast(31);
    ll.addLast(41);
    ll.addLast(30);
    ll.addLast(20);
    ll.addLast(10);

    // Add First
    // ll.addFirst(-10);
    // ll.addFirst(-20);

    // Add At
    ll.addAt(3, 15);

    // Get
    // cout << ll.getAt(4) << endl;

    // Remove
    // ll.removeAt(4);
    // ll.removeFirst();
    // ll.removeLast();

    ll.display();

    // cout << ll.isEmpty() << endl;
    // cout << ll.getSize() << endl;

    // ll.rdi();

    // ll.display();

    // ll.rpi();


    // ll.dispRev();

    // ll.rdr();
    // ll.rdr2p();
    // ll.rpr();
    

    // cout << ll.isPallin() << endl;
    // ll.fold();
    // ll.display();

    // ll.unfold();
    // ll.display();

    // cout << ll.kfl(3) << endl;
    // cout << ll.kfl_wo_size(4) << endl;

    // ll.kReverse(3);
    // ll.oddEven();

    // LinkedList* dupll = new LinkedList();

    // dupll->addLast(1);
    // dupll->addLast(1);
    // dupll->addLast(1);
    // dupll->addLast(2);
    // dupll->addLast(2);
    // dupll->addLast(3);
    // dupll->addLast(3);
    // dupll->addLast(4);

    // dupll->display();
    // dupll->removeDupSorted();
    // dupll->display();

    // cout << ll.midElement() << endl;
    cout << ll.kFromLast_slowFast(7) << endl;

}