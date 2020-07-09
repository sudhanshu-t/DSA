#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

Node* merge(Node* h1, Node* h2){
    Node* head;

    if(h1->data <= h2->data){
        head = new Node(h1->data);
        Node* rem = h1;
        h1 = h1->next;
        rem->next = NULL;
        delete rem;
    } else {
        head = new Node(h2->data);
        Node* rem = h2;
        h2 = h2->next;
        rem->next = NULL;
        delete rem;
    }
    
    Node* temp = head;
    
    while(h1 != NULL && h2 != NULL){
        if(h1->data <= h2->data){
            temp->next = h1;
            temp = temp->next;
            
            h1 = h1->next;
            
            temp->next = NULL;
        } else {
            temp->next = h2;
            temp = temp->next;
            
            h2 = h2->next;
            
            temp->next = NULL;
        }
    }
    
    if(h1 == NULL){
        temp->next = h2;
        return head;
    } else {
        temp->next = h1;
        return head;
    }
}

Node* mergeSort(Node* head) {
    // your code here
    if(head->next == NULL){
        return head;
    }
    
    Node* slow = head;
    Node* fast = head;

    while(fast->next != NULL && fast->next->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    
    Node* h1 = head;
    Node* h2 = slow->next;
    slow->next = NULL;

    h1 = mergeSort(h1);
    h2 = mergeSort(h2);
    
    head = merge(h1, h2);
    return head;
}

//Position this line where user code will be pasted.
void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}
void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}
int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        a = mergeSort(a);
        printList(a);
    }
    return 0;
}