#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <list>

using namespace std;

class Node{
    public:
    int data;
    vector<Node*> children;

    Node(int data){
        this->data = data;
    }
};

Node* construct(vector<int>& dlist){
    Node* root = NULL;
    vector<Node*> nlist;

    for(int i = 0; i < dlist.size(); i++){
        if(dlist[i] == -1){
            nlist.pop_back();
        }

        else {
            Node* nn = new Node(dlist[i]);

            if(nlist.size() == 0){
                root = nn;
            }

            else {
                Node* lastn = nlist.back();
                lastn->children.push_back(nn);
            }

            nlist.push_back(nn);
        }
    }

    return root;
}

void display(Node* root){
    string s = to_string(root->data) + " -> ";

    for(int i = 0; i < root->children.size(); i++){
        s += to_string(root->children[i]->data) + ", ";
    }

    s += ".";

    cout << s << endl;

    for(int i = 0; i < root->children.size(); i++){
        display(root->children[i]);
    }
}

int size(Node* root){
    int s = 0;

    for(int i = 0; i < root->children.size(); i++){
        s += size(root->children[i]);
    }

    return s+1;
}

int max(Node* root){
    int m = root->data;

    for(int i = 0; i < root->children.size(); i++){
        int mc = max(root->children[i]);
        m = (m >= mc) ? m : mc;
    }

    return m;
}

int height(Node* root){
    int h = 0;

    for(int i = 0; i < root->children.size(); i++){
        int hc = height(root->children[i]);
        h = (h >= hc) ? h : hc;
    }

    return h+1;
}

bool find(Node* root, int data){
    bool found = false;

    if(root->data == data){
        return true;
    }

    else {
        for(int i = 0; i < root->children.size(); i++){
            found = find(root->children[i], data);

            if(found == true){
                return found;
            }
        }
    }

    return found;
}

vector<int>* n2rp(Node* root, int data){
    if(root->data == data){
        vector<int>* br = new vector<int>();
        br->push_back(data);
        return br;
    }

    else {
        for(int i = 0; i < root->children.size(); i++){
            vector<int>* rr = n2rp(root->children[i], data);

            if(rr != NULL){
                rr->push_back(root->data);
                return rr;
            }
        }
    }

    return NULL;
}

int lca(Node* root, int d1, int d2){
    vector<int>* p1 = n2rp(root, d1);
    vector<int>* p2 = n2rp(root, d2);

    int i = p1->size()-1;
    int j = p2->size()-1;

    while(true){
        if(i >= 0 && j >= 0 && p1->at(i) == p2->at(j)){
            i--;
            j--;
        }

        else {
            return p1->at(i+1);
        }
    }
}

int distance(Node* root, int d1, int d2){
    vector<int>* p1 = n2rp(root, d1);
    vector<int>* p2 = n2rp(root, d2);

    int i = p1->size()-1;
    int j = p2->size()-1;

    while(true){
        if(i >= 0 && j >= 0 && p1->at(i) == p2->at(j)){
            i--;
            j--;
        }

        else {
            int d = p1->size()-i-1;

            return p1->size() + p2->size() - 2*d + 1;
        }
    }
}

void mirror(Node* root){
    for(int i = 0; i < root->children.size(); i++){
        mirror(root->children[i]);
    }

    int size = root->children.size();
    for(int i = 0; i < size/2; i++){
        Node* temp = root->children[i];
        root->children[i] = root->children[size-i-1];
        root->children[size-i-1] = temp;
    }
}

void removeLeaves(Node* root){
    vector<Node*> newChildren;

    for(int i = 0; i < root->children.size(); i++){
        if(root->children[i]->children.size() == 0){
            delete root->children[i];
        } else {
            newChildren.push_back(root->children[i]);
            removeLeaves(root->children[i]);
        }
    }

    root->children = newChildren;
}

Node* linearize(Node* root){
    Node* tail = root; // why is this initialization necessary?? To be able to pushback in its children
    
    for(int i = 0; i < root->children.size(); i++){
        tail = linearize(root->children[i]);

        if(i < root->children.size()-1)
            tail->children.push_back(root->children[i+1]);
    }
    
    while(root->children.size() > 1){
        root->children.pop_back();
    }

    return tail;
}

bool areSimilarStructure(Node* r1, Node* r2){
    if(r1->children.size() != r2->children.size()){
        return false;
    }
    
    bool childrenAreSim = false;
    for(int i = 0; i < r1->children.size(); i++){
        childrenAreSim = areSimilarStructure(r1->children[i], r2->children[i]);

        if(!childrenAreSim){
            return false;
        }
    }

    return true;
}

bool areMirrorStructure(Node* r1, Node* r2){
    if(r1->children.size() != r2->children.size()){
        return false;
    }

    bool cam = false;

    for(int i = 0; i < r1->children.size(); i++){
        cam = areMirrorStructure(r1->children[i], r2->children[r2->children.size() - i - 1]);

        if(!cam){
            return false;
        }
    }

    return true;
}

bool isSymmetric(Node* root){
    Node* left = root->children[0];
    Node* right = root->children[root->children.size() - 1];

    bool acs = false;

    for(int i = 0; i < root->children.size() / 2; i++){
        acs = areMirrorStructure(root->children[i], root->children[root->children.size() - i - 1]);

        if(acs == false){
            return false;
        }
    }

    if(root->children.size()%2 != 0 && areMirrorStructure(root->children[root->children.size() / 2], root->children[root->children.size() / 2])){
        return true;
    }

    return false;
}

bool isSymmetric2(Node* root){
    return areMirrorStructure(root, root);
}

void multiSolver(Node* root, int depth, int* szp, int* htp, int* mxp, int* mnp){
    // Size
    (*szp)++;

    // Height
    (*htp) = (*htp > depth) ? *htp : depth;

    // Max
    (*mxp) = (root->data > (*mxp)) ? root->data : (*mxp);

    // Min
    (*mnp) = (root->data < (*mnp)) ? root->data : (*mnp);

    for(int i = 0; i < root->children.size(); i++){
        multiSolver(root->children[i], depth+1, szp, htp, mxp, mnp);
    }
}

void ceilFloor(Node* root, int* ceilp, int* floorp, int data){
    // Ceil
    *ceilp = (root->data > data && root->data < *ceilp) ? root->data : *ceilp;
    // cout << (*ceilp) << endl;

    // Floor
    *floorp = (root->data < data && root->data > *floorp) ? root->data : *floorp;
    // cout << (*floorp) << endl;

    for(int i = 0; i < root->children.size(); i++){
        ceilFloor(root->children[i], ceilp, floorp, data);
    }
}

void predSucc(Node* root, int& pred, int& succ, int& state, int data){
    if(state == 0){
        if(root->data != data){
            pred = root->data;
        } else {
            state = 1;
        }
    }

    else if (state == 1){
        succ = root->data;
        state++;
        return;
    }

    for(int i = 0; i < root->children.size(); i++){
        predSucc(root->children[i], pred, succ, state, data);
    }
}

int kthLargest(Node* root, int data, int k){
    int fp = INT_MIN, cp = INT_MAX;

    for(int i = 0; i < k; i++){
        ceilFloor(root, &cp, &fp, data);
        data = fp;
        fp = INT_MIN;
    }

    return data;
}

void BFS_levelOrderTraversal(Node* root){
    list<Node*> q;

    q.push_back(root);

    while(!q.empty()){
        Node* front = q.front();
        q.pop_front();
        cout << front->data << " ";

        for(int i = 0; i < front->children.size(); i++){
            q.push_back(front->children[i]);
        }
    }

    cout << endl;
}

void levelOrderLineWise1(Node* root){
    list<Node*> q;
    q.push_back(root);
    q.push_back(NULL);

    while(!q.empty()){
        Node* front = q.front();

        q.pop_front();

        if(front == NULL){
            cout << endl;

            if(!q.empty())
                q.push_back(NULL);
        }

        else {
            cout << front->data << " ";

            for(int i = 0; i < front->children.size(); i++){
                q.push_back(front->children[i]);
            }
        }
    }
}

void levelOrderLineWise2(Node* root){
    list<Node*>* curr = new list<Node*>();
    list<Node*>* next = new list<Node*>();

    curr->push_back(root);

    while(curr->empty() != true){
        Node* front = curr->front();

        curr->pop_front();

        cout << front->data << " ";

        for(int i = 0; i < front->children.size(); i++){
            next->push_back(front->children[i]);
        }

        if(curr->empty() == true){
            delete curr;
            
            curr = next;
            next = new list<Node*>();

            cout << endl;
        }
    }

    delete curr;
    delete next;
}

int main(int argc, char** argv){
    vector<int> dlist = {
        10, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80, 110, -1, 120, -1, -1, 90, -1, -1, 40, 100, -1, -1, -1
    };

    Node* root = construct(dlist);
    display(root);

    cout << size(root) << endl;
    cout << max(root) << endl;
    cout << height(root) << endl;

    cout << find(root, 1000) << endl;

    vector<int>* res = n2rp(root, 500);

    if(res != NULL)
        for(int i = 0; i < res->size(); i++){
            cout << res->at(i) << " ";
        }

    cout << endl;

    cout << lca(root, 10, 50) << endl;
    cout << distance(root, 70, 90) << endl;

    // display(root);
    // mirror(root);
    // cout << "=============================" << endl;
    // display(root);
    
    cout << "-----------------------------" << endl;
    // removeLeaves(root);
    // display(root);
    cout << "-----------------------------" << endl;
    linearize(root);
    display(root);

    Node* r1 = construct(dlist);
    Node* r2 = construct(dlist);

    removeLeaves(r2);

    cout << areSimilarStructure(r1, r2) << endl;
    cout << areMirrorStructure(r1, r2) << endl;
    cout << isSymmetric(r2) << endl;
    cout << isSymmetric2(r2) << endl;

    cout << "-----------------------------" << endl;

    int height = 0, max = INT_MIN, min = INT_MAX, size = 0;

    multiSolver(r1, 0, &size, &height, &max, &min);

    cout << size << endl;
    cout << height << endl;
    cout << max << endl;
    cout << min << endl;

    cout << "-----------------------------" << endl;

    int ceil = -1, floor = -1;

    ceilFloor(r1, &ceil, &floor, 60);

    cout << ceil << endl;
    cout << floor << endl;

    cout << "-----------------------------" << endl;

    int pred = -1, succ = -1, state = 0;

    predSucc(r1, pred, succ, state, 110);
    cout << pred << " " << succ << endl;
    cout << "-----------------------------" << endl;

    cout << kthLargest(r1, INT_MAX, 8) << endl;

    // BFS_levelOrderTraversal(r1);

    // levelOrderLineWise1(r1);
    levelOrderLineWise2(r1);

    return 0;
}