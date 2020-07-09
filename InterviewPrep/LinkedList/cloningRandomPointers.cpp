#include<iostream>
using namespace std;
class Node {
    public:
    int data;
    Node* next;
    Node* arb;
    Node(int d) { 
        data = d;
        next = arb = NULL; 
    }
};
    
Node* head;

void display(Node* head){
    while(head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node* EvenListHead(Node* head) {
// write your code here

    Node* prev = head;
    Node* curr = head->next;
    Node* ohe = curr;

    while(prev->next != NULL && curr->next != NULL){
        prev->next = prev->next->next;
        curr->next = curr->next->next;

        prev = prev->next;
        curr = curr->next;
    }

    if(prev->next == NULL){
        return ohe;
    } else {
        prev->next = NULL;
        return ohe;
    }
}

/*This is a function problem.You only need to complete the function given below*/
// function to copy linked list
class Clone {
    public:
    Node* copyList(Node* n) {
        // your code here
        
        Node* temp = n;
        while(temp != NULL){
            Node* nn = new Node(temp->data);
            Node* tnext = temp->next;
            temp->next = nn;
            nn->next = tnext;
            temp = temp->next->next;

            // cout << "Formed " << nn->data << endl;
        }

        // display(n);

        temp = n;
        while(temp != NULL){
            if(temp->arb != NULL){
                temp->next->arb = temp->arb->next;
            }
            temp = temp->next->next;
        }

        // cout << n << endl;
        n = EvenListHead(n);
        // cout << n << endl;

        // display(n);
        temp = n;
        // while(temp != NULL){
        //     if(temp->arb){
                // cout << temp->data << " random to " << temp->arb->data << endl;
        //     }
        //     temp = temp->next;
        // }
        
        return n;
    }
};
    
void addToTheLast(Node* node) {
    if (head == NULL) {
        head = node;
    } else {
        Node* temp = head;
        while (temp->next != NULL) temp = temp->next;
        temp->next = node;
    }
}

bool validation(Node* head, Node* res, Node* cloned_add,
                        Node* generated_add) {
    if (generated_add == cloned_add) return false;
    Node* temp1 = head;
    Node* temp2 = res;
    int len1 = 0, len2 = 0;
    while (temp1 != NULL) {
        len1++;
        temp1 = temp1->next;
    }
    while (temp2 != NULL) {
        len2++;
        temp2 = temp2->next;
    }
    /*if lengths not equal */
    if (len1 != len2){
        cout << "1" << endl;
        return false;
    }
    temp1 = head;
    temp2 = res;
    while (temp1 != NULL) {
        if (temp1->data != temp2->data){
            cout << "2" << endl;
            return false;
        }
        if (temp1->arb != NULL && temp2->arb != NULL) {
            if (temp1->arb->data != temp2->arb->data){
                cout << "3" << endl;
                return false;
            }
        } else if (temp1->arb != NULL && temp2->arb == NULL){
            cout << "4" << endl;
            return false;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return true;
}

int main(int argc, char** argv) {
        Node* generated_add = NULL;
        int n, q, a1;
        cin>>n>>q>>a1;
        Node* head = new Node(a1);
        addToTheLast(head);
        for (int i = 1; i < n; i++) {
            int a;
            cin>>a;
            addToTheLast(new Node(a));
        }
        for (int i = 0; i < q; i++) {
            int a, b;
            cin>>a>>b;
            Node* tempA = head;
            int count = -1;
            while (tempA != NULL) {
                count++;
                if (count == a - 1) break;
                tempA = tempA->next;
            }
            Node* tempB = head;
            count = -1;
            while (tempB != NULL) {
                count++;
                if (count == b - 1) break;
                tempB = tempB->next;
            }
            // when both a is greater than N
            if (a <= n) tempA->arb = tempB;
        }
        generated_add = head;
        Clone* g = new Clone();
        Node* res = g->copyList(head);
        Node* cloned_add = res;
        if (validation(head, res, cloned_add, generated_add) == true)
            // cout<<"1";
            display(res);
        else
            cout<<"false";
    
}