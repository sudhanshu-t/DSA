#include <iostream>
#include <list>
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

Node *head1 = NULL;
Node *tail1 = NULL;
int size1 = 0;

Node *head2 = NULL;
Node *tail2 = NULL;
int size2 = 0;

void insert1(int data)
{

    Node *nn = new Node(data, NULL);
    if (head1 == NULL)
    {
        head1 = nn;
        tail1 = nn;
    }
    else
    {
        tail1->next = nn;
        tail1 = nn;
    }
    size1++;
}

void insert2(int data)
{

    Node *nn = new Node(data, NULL);
    if (head2 == NULL)
    {
        head2 = nn;
        tail2 = nn;
    }
    else
    {
        tail2->next = nn;
        tail2 = nn;
    }
    size1++;
}

void display(Node *head)
{
    for (Node *node = head; node != NULL; node = node->next)
    {
        cout << node->data << " ";
    }
}

int countpair(Node *head1, Node *head2, int x)
{
    Node* temp1 = head1;
    Node* temp2 = head2;

    int l1[10000] = {0};

    while(temp1){
        int i = temp1->data;
        l1[i]++;

        temp1 = temp1->next;
    }

    int count = 0;
    while(temp2){
        int p2 = temp2->data;

        count = count + l1[x-p2];

        temp2 = temp2->next;
    }

    return count;
}

int main()
{
    int n1 = 0, n2 = 0, x = 0;
    cin >> n1;
    for (int i = 0; i < n1; i++)
    {
        int a;
        cin >> a;
        insert1(a);
    }

    cin >> n2;

    for (int i = 0; i < n2; i++)
    {
        int a = 0;
        cin >> a;
        insert2(a);
    }

    cin >> x;

    cout << countpair(head1, head2, x);

    return 0;
}