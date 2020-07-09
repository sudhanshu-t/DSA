// Count of nodes for which subtree sum > parent
// Diameter in O(n)
// Leaf to leaf, node to node

#include <iostream>
#include <vector>
#include <stack>
#include <climits>
#include <queue>

using namespace std;

class TreeNode{
    public:
    int data;
    vector<TreeNode*>* children;

    TreeNode(int d){
        data = d;
        children = new vector<TreeNode*>();
    }
};

class Node{
public:
};

TreeNode* construct(vector<int>& dlist){
    stack<TreeNode*> st;

    TreeNode* root = new TreeNode(dlist[0]);
    st.push(root);

    for(int i = 1; i < dlist.size() - 1; i++){
        if(dlist[i] == -1){
            TreeNode* childNode = st.top(); st.pop();
            TreeNode* parentNode = st.top(); st.pop();

            parentNode->children->push_back(childNode);

            st.push(parentNode);
        } else {
            TreeNode* nn = new TreeNode(dlist[i]);
            st.push(nn);
        }
    }

    return root;
}

void display(TreeNode* root){
    cout << root->data << " -> ";

    for(int i = 0; i < root->children->size(); i++){
        cout << root->children->at(i)->data << " ";
    }

    cout << endl;

    for(int i = 0; i < root->children->size(); i++){
        display(root->children->at(i));
    }
}

class Pair{
public:
    int level;
    TreeNode* node;

    Pair(TreeNode* node, int level){
        this->node = node;
        this->level = level;
    }
};

void levelOrder(TreeNode* root){
    queue<Pair> q;
    q.push(Pair (root, 1));

    int prevLevel = 1;

    while(q.size() != 0){
        Pair front = q.front();
        q.pop();

        if(front.level != prevLevel){
            prevLevel = front.level;
            cout << endl;
        }

        cout << front.node->data << " ";

        for(int i = 0; i < front.node->children->size(); i++){
            q.push(Pair (front.node->children->at(i), front.level + 1));
        }
    }
}

int size(TreeNode* root){
    int resSize = 0;

    for(int i = 0; i < root->children->size(); i++){
        resSize += size(root->children->at(i));
    }

    return resSize + 1;
}

int maxTree(TreeNode* root){
    int maxVal = INT_MIN;

    for(int i = 0; i < root->children->size(); i++){
        maxVal = max(maxVal, maxTree(root->children->at(i)));
    }

    return max(maxVal, root->data);
}

int height(TreeNode* root){
    int h = 0;

    for(int i = 0; i < root->children->size(); i++){
        h = max(h, height(root->children->at(i)));
    }

    return h+1;
}

bool find(TreeNode* root, int key){
    bool res = false;

    if(root->data == key){
        return true;
    }

    for(int i = 0; i < root->children->size(); i++){
        bool rres = find(root->children->at(i), key);

        if(rres == true){
            return true;
        }
    }

    return false;
}

vector<int>* n2rp(TreeNode* root, int key){
    vector<int>* res = new vector<int>();

    for(int i = 0; i < root->children->size(); i++){
        res = n2rp(root->children->at(i), key);
        if(res->size() != 0) {
            res->push_back(root->data);
            return res;
        }
    }

    if(res->size() == 0){
        if(root->data == key){
            res->push_back(root->data);
        }
    }

    return res;
}

int lca(TreeNode* root, int d1, int d2){
    vector<int>* n2rp1 = n2rp(root, d1);
    vector<int>* n2rp2 = n2rp(root, d2);

    int li1 = n2rp1->size() - 1;
    int li2 = n2rp2->size() - 1;

    while(li1 >= 0 && li2 >= 0 && (*n2rp1)[li1] == (*n2rp2)[li2]){
        li1--;
        li2--;
    }

    return (*n2rp1)[li1+1];
}

int distance(TreeNode* root, int d1, int d2){
    vector<int>* n2rp1 = n2rp(root, d1);
    vector<int>* n2rp2 = n2rp(root, d2);

    return n2rp1->size() + n2rp2->size() - 1;
}

void mirror(TreeNode* root){
    for(int i = 0; i < root->children->size(); i++){
        mirror(root->children->at(i));
    }

    for(int i = 0; i < root->children->size() / 2; i++){
        TreeNode* temp = root->children->at(i);
        root->children->at(i) = root->children->at(root->children->size() - i - 1);
        root->children->at(root->children->size() - i - 1) = temp;
    }
}

TreeNode* linearise(TreeNode* root){
    TreeNode* tail = root;
    for(int i = 0; i < root->children->size(); i++){
        tail = linearise(root->children->at(i));

        if(i < root->children->size() - 1)
            tail->children->push_back(root->children->at(i+1));
    }

    int size = root->children->size();
    for(int i = 0; i < size - 1; i++){
        root->children->pop_back();
    }

    return tail;
}

void removeLeaves(TreeNode* root){
    vector<TreeNode*>* newChildren = new vector<TreeNode*>();
    for(int i = 0; i < root->children->size(); i++){
        if(root->children->at(i)->children->size() != 0){
            removeLeaves(root->children->at(i));
            newChildren->push_back(root->children->at(i));
        }
    }

    vector<TreeNode*>* temp = root->children;
    root->children = newChildren;

    delete temp;
}

bool areSimilarStructured(TreeNode* root1, TreeNode* root2){
    if(root1->children->size() != root2->children->size()){
        return false;
    }
    
    for(int i = 0; i < root1->children->size(); i++){
        if(!areSimilarStructured(root1->children->at(i), root2->children->at(i))){
            return false;
        }
    }

    return true;
}

bool areMirrorStructured(TreeNode* root1, TreeNode* root2){
    if(root1->children->size() != root2->children->size()){
        return false;
    }

    for(int i = 0; i < root1->children->size() / 2; i++){
        if(!areMirrorStructured(root1->children->at(i), root2->children->at(root2->children->size() - i - 1))){
            return false;
        }
    }

    if(root1->children->size() % 2 == 1){
        if(areMirrorStructured(root1->children->at(root1->children->size() / 2), 
                               root2->children->at(root2->children->size() / 2))){
            return true;
        } else {
            return false;
        }
    }

    return true;
}

bool isSymmetric(TreeNode* root){
    for(int i = 0; i < root->children->size(); i++){
        if(!areMirrorStructured(root->children->at(i), root->children->at(root->children->size() - i - 1))){
            return false;
        }
    }

    if(root->children->size() % 2 == 1){
        if(isSymmetric(root->children->at(root->children->size() / 2))){
            return true;
        } else {
            return false;
        }
    }

    return true;
}

void multiSolver(TreeNode* root, int* size, int* height, int depth, int* maxV, int* minV, int* ceil, int* floor, int key){
    *size = (*size) + 1;
    *height = max(*height, depth + 1);
    *maxV = max(*maxV, root->data);
    *minV = min(*minV, root->data);

    if(root->data > key && root->data < *ceil){
        *ceil = root->data;
    }
    if(root->data < key && root->data > *floor){
        *floor = root->data;
    }
    
    for(int i = 0; i < root->children->size(); i++){
        multiSolver(root->children->at(i), size, height, depth+1, maxV, minV, ceil, floor, key);
    }
}

void preSucc(TreeNode* root, int* pred, int* succ, int state, int key){
    if(state == 0){
        if(root->data != key){
            *pred = root->data;
        } else {
            state = 1;
        }
    }

    else if(state == 1){
        *succ = root->data;
        state++;
        return;
    }

    for(int i = 0; i < root->children->size(); i++){
        preSucc(root->children->at(i), pred, succ, state, key);
    }
}

class helper{
public:
    int state;
    TreeNode* node;

    helper(TreeNode* node, int state){
        this->node = node;
        this->state = state;
    }
};

void iterativeEuler(TreeNode* root){
    stack<helper> st;
    st.push(helper (root, 0));

    while(st.size() != 0){
        helper* top = &st.top(); // & - Making changes in the actual element of stack & not in its copy

        if(top->state == 0){
            cout << top->node->data << " pre" << endl;
            top->state++;
        } else if(top->state >= 1 && top->state <= top->node->children->size()){
            st.push(helper (top->node->children->at(top->state - 1), 0));
            if(top->state > 1){
                cout << top->node->data << " in" << endl;
            }
            top->state++;
        } else if(top->state == top->node->children->size() + 1){
            cout << top->node->data << " post" << endl;
            top->state++;
        } else if(top->state == top->node->children->size() + 2){
            st.pop();
        }
    }
}

string codes[] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "uv", "wx", "yz"};

class kpc{
public:
    string ans;
    string ques;
    int state;

    kpc(string ques, string ans, int state){
        this->ans = ans;
        this->ques = ques;
        this->state = state;
    }
};

void kpcIterative(){
    stack<kpc> st;
    st.push(kpc ("682", "", 0));

    while(st.size() != 0){
        kpc* top = &st.top();

        if(top->ques.size() != 0){
            char c = top->ques[0];
            string code = codes[c - '0' - 1];

            if(top->state >= 0 && top->state < code.size()){
                string newAns = top->ans + code[top->state];
                string newQues = top->ques.substr(1);
                st.push(kpc (newQues, newAns, 0));

                top->state++;
            } else {
                st.pop();
            }
        } else {
            cout << top->ans << endl;
            st.pop();
        }
    }
}

int diameter(TreeNode* root){    
    int myMax = INT_MIN;
    for(int i = 0; i < root->children->size(); i++){
        myMax = max(myMax, diameter(root->children->at(i)));
    }

    int maxHeight = 0;
    int maxHghtIdx = -1;
    for(int i = 0; i < root->children->size(); i++){
        int hght = height(root->children->at(i));
        if(hght > maxHeight){
            maxHeight = hght;
            maxHghtIdx = i;
        }
    }

    int secondMaxHeight = 0;
    for(int i = 0; i < root->children->size(); i++){
        int hght = height(root->children->at(i));
        if(i != maxHghtIdx && hght > secondMaxHeight){
            secondMaxHeight = hght;
        }
    }

    int myDia = maxHeight + secondMaxHeight + 1;
        
    return max(myDia, myMax);
}

int maxN2L = 0;
int n2l(TreeNode* root){
    int maxPath = 0;
    for(int i = 0; i < root->children->size(); i++){
        maxPath = max(maxPath, n2l(root->children->at(i)));
        maxN2L = max(maxN2L, n2l(root->children->at(i)));
    }

    maxN2L = max(maxN2L, root->data + maxPath);

    return root->data + maxPath;
}

int main(int argc, char** argv){
    vector<int> dlist = {
        10,20,50,-1,60,-1,-1,30,70,-1,80,110,-1,120,-1,-1,90,-1,-1,40,100,-1,-1,-1
    };
    vector<int> dlist2 = {
        1,2,5,-1,6,-1,-1,3,7,-1,8,11,-1,12,-1,-1,9,-1,-1,4,10,-1,105,-1,-1,-1
    };

    TreeNode* root = construct(dlist);
    TreeNode* root2 = construct(dlist2);
    display(root);

    // cout << size(root) << endl;
    // cout << maxTree(root) << endl;
    // cout << height(root) << endl;
    // cout << find(root, 9000) << endl;

    // vector<int>* n2rpath = n2rp(root, 110);
    // cout << n2rpath->size() << endl;

    // for(int i = 0; i < n2rpath->size(); i++){
    //     cout << (*n2rpath)[i] << " ";
    // }
    // cout << endl;

    // cout << lca(root, 10, 60) << endl;
    // cout << distance(root, 110, 10) << endl;

    // mirror(root);
    // levelOrder(root);

    // removeLeaves(root);
    // display(root);

    // linearise(root);
    // display(root);

    // cout << areSimilarStructured(root, root2) << endl;
    // cout << areMirrorStructured(root, root2) << endl;
    // cout << isSymmetric(root2) << endl;

    // int size = 0;
    // int height = 0;
    // int maxV = INT_MIN;
    // int minV = INT_MAX;
    // int ceil = INT_MAX;
    // int floor = INT_MIN;
    // multiSolver(root, &size, &height, 0, &maxV, &minV, &ceil, &floor, 110);

    // cout << size << endl;
    // cout << height << endl;
    // cout << maxV << endl;
    // cout << minV << endl;
    // cout << ceil << endl;
    // cout << floor << endl;

    // int pred, succ, state = 0;
    // preSucc(root, &pred, &succ, 0, 40);
    // cout << pred << " " << succ << endl;

    // iterativeEuler(root);
    // kpcIterative();

    // cout  << diameter(root) << endl;

    n2l(root);
    cout << maxN2L << endl;
}