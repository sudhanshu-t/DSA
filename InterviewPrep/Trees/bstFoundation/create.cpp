#include <iostream>
#include <string>
#include <algorithm>
#include <list>
#include <stack>
#include <vector>

using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int d){
        this->data = d;
        left = right = NULL;
    }
};

Node* constructSlave(int* dlist, int n, int lo, int hi){
    if(lo > hi){
        return NULL;
    }

    int mid = (hi + lo) / 2;

    int data = dlist[mid];
    Node* root = new Node(data);

    root->left = constructSlave(dlist, n, lo, mid - 1);
    root->right = constructSlave(dlist, n, mid + 1, hi);

    return root;
}

Node* construct(int* dlist, int n){
    sort(dlist, dlist + n);

    for(int i = 0; i < n; i++){
        cout << dlist[i] << " ";
    }
    cout << endl;

    return constructSlave(dlist, n, 0, n-1);
}

void display(Node* root){
    if(root == NULL){
        return;
    }

    string s;

    s += (root->left) ? to_string(root->left->data) : " .";
    s += " <= " + to_string(root->data) + " => ";
    s += (root->right) ? to_string(root->right->data) : ". ";

    cout << s << endl;

    display(root->left);
    display(root->right);
}

int height(Node* root){
    if(root == NULL){
        return 0;
    }
    
    int lh = height(root->left);
    int rh = height(root->right);

    return max(lh, rh) + 1;
}

bool find(Node* root, int key){
    if(root == NULL){
        return false;
    }

    if(root->data < key){
        return find(root->right, key);
    } else if(root->data > key){
        return find(root->left, key);
    } else {
        return true;
    }
}

void largerSumRecursive(Node* root, int &sum){
    if(root == NULL){
        return;
    }

    largerSumRecursive(root->right, sum);
    int temp = root->data;
    root->data = sum;
    sum += temp;
    largerSumRecursive(root->left, sum);
}

class Pair{
public:
    Node* root;
    int state;

    Pair(Node* root, int state){
        this->root = root;
        this->state = state;
    }
};

void largerSumIterative(Node* root){
    list<Pair> st;
    int sum = 0;

    st.push_front(Pair (root, 0));

    while(st.size() > 0){
        Pair* top = &st.front();

        if(top->root == NULL){
            st.pop_front();
            continue;
        }

        if(top->state == 0){
            st.push_front(Pair (top->root->right, 0));
            top->state++;
        } else if(top->state == 1){
            // Inorder
            int temp = top->root->data;
            top->root->data = sum;
            sum += temp;
            top->state++;
        } else if(top->state == 2){
            st.push_front(Pair (top->root->left, 0));
            top->state++;
        } else {
            st.pop_front();
        }
    }
}

void inorderStepWise(Node* root, stack<Pair> &st){
    if(st.size() == 0){
        st.push(Pair (root, 0));
    }

    while(st.size() > 0){
        Pair* top = &st.top();

        if(top->root == NULL){
            st.pop();
            continue;
        }

        if(top->state == 0){
            st.push(Pair (top->root->left, 0));
            top->state++;
        } else if(top->state == 1){
            // Inorder
            top->state++;
            return;
        } else if(top->state == 2){
            st.push(Pair (top->root->right, 0));
            top->state++;
        } else {
            st.pop();
        }
    }
}

void reverseInorderStepWise(Node* root, stack<Pair> &st){
    if(st.size() == 0){
        st.push(Pair (root, 0));
    }
    
    while(st.size() > 0){
        Pair* top = &st.top();

        if(top->root == NULL){
            st.pop();
            continue;
        }

        if(top->state == 0){
            st.push(Pair (top->root->right, 0));
            top->state++;
        } else if(top->state == 1){
            // reverse inorder
            top->state++;
            return;
        } else if(top->state == 2){
            st.push(Pair (top->root->left, 0));
            top->state++;
        } else {
            st.pop();
        }
    }
}

vector<int>* targetSum(Node* root, int target){
    stack<Pair> left;
    stack<Pair> right;

    inorderStepWise(root, left);
    reverseInorderStepWise(root, right);

    int leftData = left.top().root->data;
    int rightData = right.top().root->data;

    vector<int>* result = new vector<int>();

    while(left.top().root != right.top().root){
        cout << leftData + rightData << endl;
        
        if(target > leftData + rightData){
            inorderStepWise(root, left);
        } else if(target < leftData + rightData){
            reverseInorderStepWise(root, right);
        } else {
            result->push_back(leftData);
            result->push_back(rightData);
            break;
        }

        leftData = left.top().root->data;
        rightData = right.top().root->data;
    }

    return result;
}

void printInRange(Node* root, int lo, int hi){
    
}

void findSumPath(Node* root, int target, int sumSoFar, string asf){
    if(root == NULL){
        return;
    }
    
    if(root->left == NULL && root->right == NULL){
        sumSoFar += root->data;

        if(sumSoFar == target){
            cout << asf << root->data << endl;
        }

        return;
    }

    findSumPath(root->left, target, sumSoFar + root->data, asf + to_string(root->data) + " ");
    findSumPath(root->right, target, sumSoFar + root->data, asf + to_string(root->data) + " ");
}

Node* addNode(Node* root, int data){
    if(root == NULL){
        Node* nn = new Node(data);
        return nn;
    }
    
    if(data > root->data){
        root->right = addNode(root->right, data);
    } else if(data < root->data){
        root->left = addNode(root->left, data);
    }

    return root;
}

void addNode2(Node* root, int data){
    if(data > root->data){
        if(root->right != NULL){
            addNode(root->right, data);
        } else {
            Node* nn = new Node(data);
            root->right = nn;
        }
    } else {
        if(root->left != NULL){
            addNode(root->left, data);
        } else {
            Node* nn = new Node(data);
            root->left = nn;
        }
    }
}

Node* max(Node* root){
    while(root->right != NULL){
        root = root->right;
    }

    return root;
}

Node* removeNode(Node* root, int data){
    if(root == NULL){
        return NULL;
    }
    
    if(data > root->data){
        root->right = removeNode(root->right, data);
        return root;
    } else if(data < root->data){
        root->left = removeNode(root->left, data);
        return root;
    } else {
        if(root->left != NULL && root->right != NULL){
            Node* maxLeft = max(root->left);
            root->data = maxLeft->data;
            root->left = removeNode(root->left, maxLeft->data);
            return root;
        } else if(root->left != NULL){
            Node* rem = root->left;
            delete root;
            return rem;
        } else if(root->right != NULL){
            Node* rem = root->right;
            delete root;
            return rem;
        } else {
            delete root;
            return NULL;
        }
    }
}

int main(int argc, char** argv){
    int dlist[] = {50,20,10,30,60,80,80};
    int size = sizeof(dlist) / sizeof(int);

    Node* root = construct(dlist, size);

    cout << root->data << endl;
    display(root);

    cout << height(root) << endl;
    cout << find(root, 87) << endl;

    int sum = 0;
    // largerSumRecursive(root, sum);
    // largerSumIterative(root);
    // display(root);

    // vector<int>* pair = targetSum(root, 9000);
    // if(pair->size() != 0){
    //     cout << pair->at(0) << " " << (*pair)[1] << endl;
    // } else {
    //     cout << "Not found!" << endl;
    // }

    // findSumPath(root, 250, 0, "");

    // addNode2(root, 65);
    // display(root);

    removeNode(root, 20);
    display(root);

}