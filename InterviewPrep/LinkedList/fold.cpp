#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data, Node *next)
    {
        this->data = data;
        this->next = next;
    }
};

Node *head = NULL;

/*
    * Input Parameters: tail: tail of the linked list in which a new node is to
    * be inserted. data: the data value of the node which is to be inserted.
    * 
    * Return Value: tail of the linked list in which the node is inserted
*/

Node *insert(Node *tail, int data)
{
    if (tail == NULL)
    {
        return new Node(data, NULL);
    }
    else
    {
        tail->next = new Node(data, NULL);
        return tail->next;
    }
}

/*
    * Input Parameters: head: head of the linked list in which is to be
    * displayed.
    * 
    * Return Value: null
*/

void display(Node *head)
{
    for (Node *node = head; node != NULL; node = node->next)
    {
        cout << node->data << " ";
    }
    cout << endl;
}

// -----------------------------------------------------
// This is a functional problem. Only this function has to be written.
// This function takes as input the head of the linked list.
// It should return the head of the rearranged linked list.

Node* rpi(Node* head){
    Node* prev = NULL;
    Node* curr = head;
    Node* next = curr->next;

    // cout << curr->data << endl;

    while(curr != NULL){
        curr->next = prev;
        // cout << curr->data << " Points to " << prev->data << endl;
        prev = curr;
        curr = next;

        if(next != NULL)
            next = next->next;

        // cout << prev->data << " " << curr->data << " " << next->data << endl;
    }

    return prev;
}

Node* mergeAlt(Node* head1, Node* head2){
        //write your code here, and print the result

    Node* temp1 = head1;
    Node* temp2 = head2;

    Node* nn = NULL;
    while(temp1 != NULL){
        // System.out.println("Added " + temp2.data);
        // Removing first element of 2nd
        Node* rem = temp2;
        int data = temp2->data;
        temp2 = temp2->next;
        rem->next = NULL;
        delete rem;

        // Adding in 1st after temp1
        nn = new Node(data, NULL);
        nn->next = temp1->next;
        temp1->next = nn;
        temp1 = temp1->next->next;
    }

    if(temp2 != NULL){
        nn->next = temp2;
    }

    return head1;
}

Node* rearrange(Node* node)
{
    if(node->next == NULL){
        return node;
    }
    
    // write your code here
    Node* prev = NULL;
    Node* slow = node;
    Node* fast = node;

    while(fast != NULL && fast->next != NULL){
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    prev->next = NULL;

    slow = rpi(slow);
    node = mergeAlt(node, slow);

    return node;
}

// -----------------------------------------------------

int main()
{
    int s;
    cin >> s;
    int a;
    cin >> a;
    head = insert(NULL, a);
    Node *tail = head;
    for (int i = 1; i < s; i++)
    {
        int temp;
        cin >> temp;
        tail = insert(tail, temp);
    }

    Node* rehead = rearrange(head);
    display(rehead);

}