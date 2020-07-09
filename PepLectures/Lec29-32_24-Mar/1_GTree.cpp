#include <iostream>
#include <vector>
#include <string>
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
    
    vector<Node*>* nlist = new vector<Node*>();

    for(int i = 0; i < dlist.size(); i++){
        Node* nn = new Node(dlist[i]);

        if(dlist[i] == -1){
            nlist->pop_back();
        }

        else{
            if(nlist->size() == 0){
                root = nn;
            }

            else{
                Node* lastN = nlist->back();
                lastN->children.push_back(nn);
            }

            nlist->push_back(nn);
        }
    }

    delete nlist;
    return root;
}

void display(Node* root){
    string s = to_string(root->data) + " -> ";
    
    for(int i = 0; i < root->children.size(); i++){
        s += to_string(root->children[i]->data) + ", ";
    }

    cout << s + "." << endl;

    for(int i = 0; i < root->children.size(); i++){
        display(root->children[i]);
    }
}

int getSize(Node* root){
    int sizeSubtree = 0;

    for(int i = 0; i < root->children.size(); i++){
        sizeSubtree += getSize(root->children[i]);
    }

    return sizeSubtree + 1;
}

int maxVal(Node* root){
    int max = root->data;

    for(int i = 0; i < root->children.size(); i++){
        int maxSubTree = maxVal(root->children[i]);

        max = (max >= maxSubTree) ? max : maxSubTree;
    }

    return max;
}

int height(Node* root){
    int h = 0;

    for(int i = 0; i < root->children.size(); i++){
        int hSubTree = height(root->children[i]);

        h = (h >= hSubTree) ? h : hSubTree;
    }

    return h+1;
}

int height_edge(Node* root){}

bool find(Node* root, int dtf){
    if(root->data == dtf){
        return true;
    }
    
    for(int i = 0; i < root->children.size(); i++){
        bool found = find(root->children[i], dtf);

        if(found){
            return found;
        }
    }

    return false;
}

vector<int>* ntrp(Node* root, int data){
    if(root->data == data){
        vector<int>* br = new vector<int>();
        br->push_back(data);
        return br;
    }

    for(int i = 0; i < root->children.size(); i++){
        // cout << root->data << " " << root->children[i]->data << " " << "a" << endl;
        vector<int>* rr = ntrp(root->children[i], data);
        // cout << root->data << " " << root->children[i]->data << " " << "b" << endl;

        if(rr->size() != 0){
            rr->push_back(root->data);
            return rr;
        }
    }

    vector<int>* kv = new vector<int>();// here new karna important hai otherwise, garbage hoga kv me.
    return kv;// null bhi return kar sakte hain. Condition will change to rr != NULL
}

int lca(Node* root, int d1, int d2){
    vector<int>* path1 = ntrp(root, d1);
    vector<int>* path2 = ntrp(root, d2);

    int i = path1->size()-1;
    int j = path2->size()-1;

    while((*path1)[i] == (*path2)[j]){
        i--;
        j--;
    }

    return (*path1)[i+1];
}

int distance(Node* root, int d1, int d2){
    vector<int>* path1 = ntrp(root, d1);
    vector<int>* path2 = ntrp(root, d2);

    int i = path1->size()-1;
    int j = path2->size()-1;

    while((*path1)[i] == (*path2)[j]){
        i--;
        j--;
    }

    int cdis = path1->size() - i - 1;

    int d = path1->size() + path2->size() - 2*cdis + 1;

    return d;
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
    int size = root->children.size();

    vector<Node*> newChildren;

    for(int i = 0; i <= size-1; i++){
        if(root->children[i]->children.size() == 0){
            // root->children.erase(root->children.begin() + i);
            delete root->children[i];
        } else {
            newChildren.push_back(root->children[i]);
            removeLeaves(root->children[i]);
        }
    }

    root->children = newChildren;
}

Node* getTail(Node* root){
    Node* temp = root;

    if(temp->children.size() != 0)
        temp = getTail(temp->children[0]);

    return temp;
}

void linearize(Node* root){
    while(root->children.size() > 1){
        Node* rLast = root->children.back();
        root->children.pop_back();

        Node* last = root->children.back();
        Node* lastTail = getTail(last);

        lastTail->children.push_back(rLast);
    }
}

// Linearize in O(N)
Node* linearize2(Node* root){
    if(root->children.size() == 0){
        return root;
    }

    Node* ol = root->children.back();
    Node* olt = linearize2(ol); // consider this call as a part of the loop; it doesn't seem like, but it is.
    
    while(root->children.size() > 1){
        Node* sl = root->children[root->children.size() - 2];
        Node* slt = linearize2(sl);

        Node* last = root->children[root->children.size() - 1];
        root->children.pop_back();

        slt->children.push_back(last);
    }

    return olt;
}

bool areSimStructure(Node* root1, Node* root2){
    if(root1->children.size() == root2->children.size()){
        if(root1->children.size() == 0){
            return true;
        }
        
        bool cass;

        for(int i = 0; i < root1->children.size(); i++){
            cass = areSimStructure(root1->children[i], root2->children[i]);
            if(!cass){
                break;
            }
        }

        if(cass){
            return cass;
        } else {
            return false;
        }
    } else {
        return false;
    }
}

bool areMirrorStructure(Node* root1, Node* root2){
    if(root1->children.size() == root2->children.size()){
        for(int i = 0; i < root1->children.size(); i++){
            bool cams = areMirrorStructure(root1->children[i], root2->children[root2->children.size() - i - 1]);
            
            if(!cams){
                return false;
            }
        }

        return true;
    } else {
        return false;
    }
}

bool isSymmetric(Node* root){
    bool cas;

    for(int i = 0; i <= root->children.size() / 2; i++){
        cas = areSimStructure(root->children[i], root->children[root->children.size() - i - 1]);

        if(!cas){
            return false;
        }
    }

    return false;
}

int countNodes(Node* root){
    int count = 0;
}

bool isSymm2(Node* root){
    return areMirrorStructure(root, root);
}

void multiSolver(Node* root, int depth, int* szp, int* htp, int* mxp, int* mnp, int* C, int* F, int data){
    (*szp)++;

    *htp = (depth > *htp) ? depth : *htp;

    *mxp = (root->data > *mxp) ? root->data : *mxp;

    *mnp = (root->data < *mnp) ? root->data : *mnp;

    // floor
    if(root->data <  data){
        *F = (root->data > *F) ? root->data : *F;
    }
    
    // ceil
    if(root->data > data){
        *C = (root->data < *C) ? root->data : *C;
    }
    
    for(int i = 0; i < root->children.size(); i++){
        multiSolver(root->children[i], depth+1, szp, htp, mxp, mnp, C, F, data);
    }
    int ceil = -1, floor = -1;
}

void ceilFloor(Node* root, int* C, int* F, int data){
    // floor
    if(root->data <  data){
        *F = (root->data > *F) ? root->data : *F;
    }
    
    // ceil
    if(root->data > data){
        *C = (root->data < *C) ? root->data : *C;
    }
    
    for(int i = 0; i < root->children.size(); i++){
        ceilFloor(root->children[i], C, F, data);
    }
}

void predSucc(Node* root, int& state, int& pred, int& succ, int data){
    if(state == 2){
        return;
    }
    
    if(state == 0){
        if(root->data != data){
            pred = root->data;
        } else {
            state++;
        }
    } else if(state == 1){
        succ = root->data;
        state++;
    }

    for(int i = 0; i < root->children.size(); i++){
        predSucc(root->children[i], state, pred, succ, data);
    }
}

void kthLargest(Node* root, int k){
    int max = maxVal(root);

    int ceil = INT_MAX, floor = INT_MIN;
    for(int i = 0; i < k-1; i++){
        ceilFloor(root, &ceil, &floor, max);

        max = floor;
        floor = INT_MIN;
    }

    cout << k << " Largest is: " << max << endl;
}

void levelOrderTraversal(Node* root){
    list<Node*> queue;

    queue.push_back(root);

    while(!queue.empty()){
        Node* node = queue.front();

        queue.pop_front();

        cout << node->data << " ";

        for(int i = 0; i < node->children.size(); i++){
            queue.push_back(node->children[i]);
        }
    }

    cout << endl;
}

void levelOrderLineWise(Node* root){
    list<Node*> queue;

    queue.push_back(root);
    queue.push_back(NULL);

    while(!queue.empty()){
        Node* node = queue.front();

        queue.pop_front();

        if(node == NULL){
            cout << endl;
                
            if(queue.size() != 0)
                queue.push_back(NULL);
        } else {
            cout << node->data << " ";

            for(int i = 0; i < node->children.size(); i++){
                queue.push_back(node->children[i]);
            }
        }
    }
}

void levelOrderLineWise2(Node* root){
    list<Node*>* curr = new list<Node*>();
    list<Node*>* next = new list<Node*>();

    curr->push_back(root);

    while(curr->size() > 0){
        Node* n = curr->front();

        curr->pop_front();

        cout << n->data << " ";

        for(int i = 0; i < n->children.size(); i++){
            next->push_back(n->children[i]);
        }

        if(curr->size() == 0){
            delete curr;

            curr = next;
            next = new list<Node*>();

            cout << endl;
        }
    }

    delete curr;
    delete next;
}

void levelOrderZigZag(Node* root){
    list<Node*>* curr = new list<Node*>();
    list<Node*>* next = new list<Node*>();

    curr->push_back(root);
    bool ltr = true;

    while(curr->size() > 0){
        Node* n = curr->front();

        curr->pop_front();

        cout << n->data << " ";

        if(ltr == true){
            for(int i = 0; i < n->children.size(); i++){
                next->push_front(n->children[i]);
            }
        } else {
            for(int i = 0; i < n->children.size(); i++){
               next->push_front(n->children[n->children.size() - i - 1]);
            }   
        }

        if(curr->size() == 0){
            delete curr;

            curr = next;
            next = new list<Node*>();
            ltr = !ltr;

            cout << endl;
        }
    }

    delete curr;
    delete next;
}

class eHelper{
    public:
    Node* root;
    int state;

    eHelper(Node* root, int state){
        this->root = root;
        this->state = state;
    }
};

void iterativeEuler(Node* root){
    eHelper* rh = new eHelper(root, 0);

    list<eHelper*> stack;

    stack.push_front(rh);

    while(stack.size() > 0){
        eHelper* th = stack.front();
        int size = th->root->children.size();

        if(th->state == 0){
            cout << th->root->data << " pre" << endl;
            th->state++;
        } else if(th->state >= 1 && th->state <= size){
            eHelper* ch = new eHelper(th->root->children[th->state - 1], 0);
            stack.push_front(ch);

            if(th->state >= 2){
                cout << th->root->data << " in " << th->state-1 << endl;
            }
            th->state++;
        } else if(th->state == size + 1){
            cout << th->root->data << " post" << endl;
            th->state++;
        } else if(th->state == size + 2){
            delete th;
            stack.pop_front();
        }
    }
}

vector<string> codes = {"abc", "def", "ghi", "jk", "lmno"};

class kpcHelper{
    public:
    string q;
    string a;
    int state;

    kpcHelper(string q, string a, int state){
        this->q = q;
        this->a = a;
        this->state = state;
    }
};

// void iterativeDepthFirstKPC(Node* root){
//     kpcHelper* rh = new kpcHelper("", "", 0);

//     list<kpcHelper*> stack;

//     stack.push_front(rh);

//     while(stack.size() > 0){
//         kpcHelper* th = stack.front();

//         if(th->q.size() == 0){
//             cout << th->a << endl;
//             stack.pop_front();
//         } else {
//             if(th->state < codes[th->q[0] - '0' - 1].size()){
//                 string q = th->q.substr(1);
//                 string a
//                 kpcHelper* ch = new kpcHelper()
//             }
//         }
//     }
// }

// Max no. edges between any pair of nodes
int diameter(Node* root){
    for(int i = 0; i < root->children.size(); i++){
    }
}

int main(int argc, char** argv){
    // vector<int> dlist {
    //     10, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80, 110, -1, 120, -1, -1, 90, -1, -1, 40, 100, -1, -1, -1
    // };

    // Node* root = construct(dlist);
    // display(root);

    // cout << endl << getSize(root) << endl;
    // cout << maxVal(root) << endl;
    // cout << height(root) << endl;
    // cout << find(root, 110) << endl;

    // vector<int>* ntrPath = ntrp(root, 110);

    // for(int i = 0; i < ntrPath->size(); i++){
    //     cout << (*ntrPath)[i] << " ";
    // }
    // cout << endl;

    // cout << "LCA " <<  lca(root, 50, 10) << endl;

    // cout << "Distance " << distance(root, 50, 100) << endl;

    // // display(root);
    // // mirror(root);
    // // cout << "MIRRORED:" << endl;
    // // display(root);

    // cout << "Remove Leaves" << endl;

    // removeLeaves(root);
    // display(root);

    // linearize2(root);
    // cout << "_____________" << endl;
    // linearize(root);

    vector<int> dlist1 {
        10, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80, 110, -1, 120, -1, -1, 90, -1, -1, 40, 100, -1, -1, -1
    };

    Node* root1 = construct(dlist1);

    // vector<int> dlist2 {
    //     10, 40, 100, -1, -1, 30, 90, -1, 80, 120, -1, 110, -1, -1, 70, -1, -1, 20, 60, -1, 50, -1, -1, -1
    // };

    // Node* root2 = construct(dlist2);

    // cout << areSimStructure(root1, root2) << endl;
    // cout << areMirrorStructure(root1, root2) << endl;

    // vector<int> dlist {
    //     10, 20, -1, 30, 50, -1, -1, 40, -1, -1
    // };

    // Node* root = construct(dlist);

    // cout << isSymmetric(root) << endl;
    // cout << isSymm2(root) << endl;
    // display(root);

    int size = 0, ht = 0, mx = INT_MIN, mn = INT_MAX;
    int minC = INT_MAX;
    int maxF = INT_MIN;
    // multiSolver(root1, 0, &size, &ht, &mx, &mn, &minC, &maxF, 100);

    // cout << size << " " << ht << " " << mx << " " << mn << endl;

    // if(minC != INT_MAX){
    //     cout << minC << endl;
    // } else {
    //     cout << "No ceil" << endl;
    // }

    // if(maxF != INT_MIN){
    //     cout << maxF << endl;
    // } else {
    //     cout << "No floor" << endl;
    // }

    // int pred = -1, succ = -1, state = 0;
    // predSucc(root1, state, pred, succ, 100);
    // cout << pred << " " << succ << endl;

    // int ceil = INT_MAX, floor = INT_MIN;
    // ceilFloor(root1, &ceil, &floor, 90);
    // cout << ceil << " " << floor << endl;

    // kthLargest(root1, 4);

    // Level Order
    // levelOrderTraversal(root1);
    // levelOrderLineWise(root1);
    // levelOrderLineWise2(root1);
    // levelOrderZigZag(root1);
    iterativeEuler(root1);

    return 0;
}