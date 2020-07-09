#include <iostream>

using namespace std;

class Node{
public:
    Node* next;
    int data;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

void findIntersection(Node* n, Node* m){
    int s1 = 0, s2 = 0;
    Node* temp = n;

    while(temp != NULL){
        temp = temp->next;
        s1++;
    }

    temp = m;

    while(temp != NULL){
        temp = temp->next;
        s2++;
    }
    
    Node* t1 = n;
    Node* t2 = m;
    
    if(s1 > s2){
        for(int i = 0; i < s1-s2; i++){
            t1 = t1->next;
        }
    } else {
        for(int i = 0; i < s2-s1; i++){
            t2 = t2->next;
        }
    }

    while(t1 != NULL){
        t1 = t1->next;
        t2 = t2->next;

        if(t1 == t2){
            cout << "Intersection Point is at " << t1->data << endl;
            return;
        }
    }
}

Node* removeLoop(Node* slow, Node* fast){
    while(fast != slow){
        slow = slow->next;
        fast = fast->next;
    }

    return fast;
}

Node* detectAndRemLoop(Node* head){
    // bool loop = false;

    Node* slow = head;
    Node* fast = head;

    while(fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast){
            // loop = true;
            return removeLoop(head, fast);
            // return true;
        }
    }

    // return loop;   
}

void display(Node* node){
    Node* temp = node;
    
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

int main(int argc, char** argv){
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    Node* n5 = new Node(5);
    Node* n6 = new Node(6);
    Node* n7 = new Node(7);
    Node* n8 = new Node(8);
    Node* n9 = new Node(9);
    Node* n10 = new Node(10);
    
    Node* m1 = new Node(11);
    Node* m2 = new Node(12);
    Node* m3 = new Node(13);
    Node* m4 = new Node(14);
    Node* m5 = new Node(15);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;
    n6->next = n7;
    n7->next = n8;
    n8->next = n9;
    n9->next = n10;
    n10->next = NULL;

    m1->next = m2;
    m2->next = m3;
    m3->next = m4;
    m4->next = m5;
    m5->next = n8;



    // cout << detectAndRemLoop(n1) << endl;

    display(n1);
    display(m1);
    
    // findIntersection(n1, m1);

    n10->next = m1;

    cout << detectAndRemLoop(n1)->data << endl;

    

    return 0;
}