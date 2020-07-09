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

void display(Node* head)
{
    for (Node *node = head; node != NULL; node = node->next)
    {
        cout << node->data << " ";
    }
}

//----------------------------------------------------
    //This is a functional problem. Only this function has to be written.
    //You should return the head of node after sorting.
Node* sort(Node* head)
{
    Node* prev = head;
    Node* curr = head->next;

    while(curr != NULL){
        cout << prev->data << " " << curr->data << endl;
        if(prev->data <= curr->data){
            prev = curr;
            curr = curr->next;
            continue;
        }

        prev->next = curr->next;
        curr->next = head;
        head = curr;
        curr = prev->next;
    }

    return head;
}
//----------------------------------------------------

int main()
{
    //Input managed
    int n=0;
    cin >> n;

    for(int i=0; i<n; i++)
    {
        int a = 0; 
        cin >> a;
        insert(a);
    }
    // cal to the function 
    Node* sortedHead = sort(head);

    //output handled 
    display(sortedHead);
    return 0;
}