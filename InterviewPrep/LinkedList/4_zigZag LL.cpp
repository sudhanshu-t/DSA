#include <iostream>
#include <vector>

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
Node *tail = NULL;
int size = 0;

void insert(int data)
{

    Node *nn = new Node(data, NULL);
    if (head == NULL)
    {
        head = nn;
        tail = nn;
    }
    else
    {
        tail->next = nn;
        tail = nn;
    }
    size++;
}

void display()
{
    for (Node *node = head; node != NULL; node = node->next)
    {
        cout << node->data << " ";
    }
}

// ---------------------------------------------------------------
    // This is a functional problem. Only this function has to be written.

void fashion(Node* head)
{   
    // write your code here
    bool flag = true;
    // true - <
    // false - >

    Node* prev = head;
    Node* curr = head->next;
    while(curr){
        if(flag && prev->data > curr->data){
            int temp = prev->data;
            prev->data = curr->data;
            curr->data = temp;
        } else if(flag == false && prev->data < curr->data){
            int temp = prev->data;
            prev->data = curr->data;
            curr->data = temp;
        }

        flag = !flag;
        prev = curr;
        curr = curr->next;
    }
}

int main()
{
    //input handled
    int n = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a = 0;
        cin >> a;
        insert(a);
    }

    // call to the function
    fashion(head);

    //output
    display();
    return 0;
}