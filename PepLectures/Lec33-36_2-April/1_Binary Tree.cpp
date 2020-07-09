#include <iostream>
#include <vector>
#include <list>
#include <climits>

using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* construct(vector<int>& dlist){
    Node* root = NULL;

    list<Node*> nlist;

    for(int i = 0; i < dlist.size(); i++){
        Node* nn = new Node(dlist[i]);

        if(dlist[i] == -1){
            nlist.pop_front();
        }

        else {
            if(nlist.size() == 0){
                root = nn;
            }

            else {
                Node* fr = nlist.front();

                if(fr->left == NULL){
                    fr->left = nn;
                }

                else {
                    fr->right = nn;
                }
            }

            nlist.push_front(nn);
        }
    }

    return root;
}

void display(Node* root){
    if(root->left){
        cout << root->left->data << " ";
    } else {
        cout << " . ";
    }

    cout << "<--" << root->data << "--> ";

    if(root->right){
        cout << root->right->data << " ";
    } else {
        cout << ". ";
    }

    cout << endl;

    if(root->left){
        display(root->left);
    }
    if(root->right){
        display(root->right);
    }
}

// Reactive
int size1(Node* root){
    if(root == NULL){
        return 0;
    }

    int ls = size1(root->left);
    int rs = size1(root->right);

    return ls+rs+1;
}

// Proactive
int size2(Node* root){
    int ls = 0, rs = 0;
    
    if(root->left){
        ls = size2(root->left);
    }

    if(root->right){
        rs = size2(root->right);
    }

    return ls+rs+1;
}

int size3(Node* root){
    int ls = 0, rs = 0;

    if(root->left && root->right){
        ls = size3(root->left);
        rs = size3(root->right);
    } else if(root->left){
        ls = size3(root->left);
    } else if(root->right){
        rs = size3(root->right);
    }

    return ls+rs+1;
}

int height(Node* root){
    if(root == NULL){
        return 0;
    }

    int lh = 0, rh = 0;

    if(root->left){
        lh = height(root->left);
    }

    if(root->right){
        rh = height(root->right);
    }

    return (lh > rh) ? lh + 1 : rh + 1;
}

int max(Node* root){
    if(root == NULL){
        return INT_MIN;
    }

    int leftMax = max(root->left);
    int rightMax = max(root->right);

    int max = (leftMax > rightMax) ? leftMax : rightMax;

    return (root->data > max) ? root->data : max;
}

int max2(Node* root){
    int lm = INT_MIN, rm = INT_MIN;
    
    if(root->left){
        lm = max2(root->left);
    }

    if(root->right){
        rm = max2(root->right);
    }

    int max = (lm > rm) ? lm : rm;

    return (root->data > max) ? root->data : max;
}

int sum(Node* root){
    int ls = 0;
    int rs = 0;

    if(root->left){
        ls = sum(root->left);
    }

    if(root->right){
        rs = sum(root->right);
    }

    return root->data + ls + rs;
}

bool find(Node* root, int data){
    if(root == NULL){
        return false;
    }

    if(root->data == data){
        return true;
    }

    bool fl = find(root->left, data);
    if(fl){
        return true;
    }

    bool fr = find(root->right, data);
    if(fr == true){
        return true;
    }

    return false;
}

vector<Node*>* n2rp(Node* root, int data){
    if(root == NULL){
        return NULL;
    }

    if(root->data == data){
        vector<Node*>* bl = new vector<Node*>();

        bl->push_back(root);
        return bl;
    }

    vector<Node*>* fl = n2rp(root->left, data);
    if(fl != NULL){
        fl->push_back(root);
        return fl;
    }

    vector<Node*>* fr = n2rp(root->right, data);
    if(fr != NULL){
        fr->push_back(root);
        return fr;
    }

    return NULL;
}

void kdown(Node* root, Node* phbt, int k){
    if(root == NULL || root == phbt){
        return;
    }

    if(k == 0){
        cout << root->data << endl;
        return;
    }

    kdown(root->left, phbt, k-1);
    kdown(root->right, phbt, k-1);
}

// ALSO TRY - K DOWN FROM A SPECIFIC NODE

void kDownFromParticularNode(Node* root, int d, int k, int state){
    if(root == NULL){
        return;
    }

    if(state == 0){
        if(root->data == d){
            kDownFromParticularNode(root->left, d, k-1, state+1);
            kDownFromParticularNode(root->right, d, k-1, state+1);
        }
        
        else {
            kDownFromParticularNode(root->left, d, k, state);
            kDownFromParticularNode(root->right, d, k, state);
        }
    }

    else if (state == 1){
        if(k == 0){
            cout << root->data << endl;
            return;
        }

        kDownFromParticularNode(root->left, d, k-1, state);
        kDownFromParticularNode(root->right, d, k-1, state);
    }
}

void printKFar2(Node* root, int d, int k){
    vector<Node*>* n2rpath = n2rp(root, d);

    for(int i = 0; i <= k && i < n2rpath->size(); i++){
        Node* phbt = (i == 0) ? NULL : n2rpath->at(i - 1);
        kdown((*n2rpath)[i], phbt, k - i);
    }
}

Node* removeLeaves2(Node* root){
    if(root == NULL){
        return NULL;
    }

    if(root->left == NULL && root->right == NULL){
        delete root;
        return NULL;
    }

    root->left = removeLeaves2(root->left);
    root->right = removeLeaves2(root->right);
}

void removeLeaves(Node* root){
    // Checking if left is leaf node
    if(root->left != NULL){
        // If yes, remove left
        if(root->left->left == NULL && root->left->right == NULL){
            root->left = NULL;
        }

        // else call to left to remove it's leaf nodes
        else {
            removeLeaves(root->left);
        }
    }

    // Checking if right is leaf node
    if(root->right != NULL){
        // If yes, remove right
        if(root->right->left == NULL && root->right->right == NULL){
            root->right = NULL;
        }

        // else call to right to remove it's leaf nodes
        else {
            removeLeaves(root->right);
        }
    }
}

void printSingleChild(Node* root){
    if(root->left != NULL && root->right != NULL){
        printSingleChild(root->left);
        printSingleChild(root->right);
    }

    else if(root->left != NULL){
        cout << root->left->data << endl;
        printSingleChild(root->left);
    }

    else if(root->right != NULL){
        cout << root->right->data << endl;
        printSingleChild(root->right);
    }

    return;
}

void path2leafInRange(Node* root, int lo, int hi, int sum, vector<int>& path){
    if(root == NULL){   
        return;
    }

// Here we have checked ek step pehele hi, that is, at the leaf; to avoid adding same path twice
    if(root->left == NULL && root->right == NULL){
        path.push_back(root->data);
        sum += root->data;

        if(sum >= lo && sum <= hi){
            for(int i = 0; i < path.size(); i++){
                cout << path[i] << " ";
            }

            cout << endl;
        }

        path.pop_back();

        return;
    }

    path.push_back(root->data);
    

    path2leafInRange(root->left, lo, hi, sum + root->data, path);
    path2leafInRange(root->right, lo, hi, sum + root->data, path);

    path.pop_back();
}

// ======== Lec 35, 6 April ========= //

Node* construct1(vector<int>& pre, vector<int>& in, int pre_lo, int pre_hi, int in_lo, int in_hi){
    if(pre_lo > pre_hi || in_lo > in_hi){
        return NULL;
    }
    
    Node* root = new Node(pre[pre_lo]);

    // count of left nodes
    int lhs = 0;

    while(in[in_lo + lhs] != pre[pre_lo]){
        lhs++;
    }

    Node* left = construct1(pre, in, pre_lo + 1, pre_lo + lhs, in_lo, in_lo + lhs - 1);
    Node* right = construct1(pre, in, pre_lo + lhs + 1, pre_hi, in_lo + lhs + 1, in_hi);

    root->left = left;
    root->right = right;

    return root;
}

Node* construct2(vector<int>& post, vector<int>& in, int post_lo, int post_hi, int in_lo, int in_hi){
    if(post_lo > post_hi || in_lo > in_hi){
        return NULL;
    }

    Node* root = new Node(post[post_hi]);

    int lhs = 0;
    while(in[in_lo + lhs] != post[post_hi]){
        lhs++;
    }

    Node* left = construct2(post, in, post_lo, post_lo + lhs - 1, in_lo, in_hi + lhs - 1);
    Node* right = construct2(post, in, post_lo + lhs, post_hi - 1, in_lo + lhs + 1, in_hi);

    root->left = left;
    root->right = right;

    return root;
}

Node* construct3(vector<int>& pre, vector<int>& post, int pre_lo, int pre_hi, int post_lo, int post_hi){

    Node* root = new Node(pre[pre_lo]);

    int lhs = 0;
    while(post[post_lo + lhs] != pre[pre_lo + 1]){
        lhs++;
    }

    root->left = construct3(pre, post, pre_lo + 1, pre_lo + lhs + 1, post_lo, post_lo + lhs + 1);
    root->right = construct3(pre, post, pre_lo + lhs + 1, pre_hi, post_hi + lhs + 1, post_hi);

    return root;
}

// Node* constructTreeDataParent(vector<int>& data, vector<int>& parent){
//     vector<Node*> new_parent = {NULL};
    
//     for(int i = 0; i < data.size(); i++){
//         if(parent[i] != -1){
//             if(new_parent[parent[i]] != NULL){
//                 Node* p = new_parent[data[i]];
//             } else {
//                 Node* p = new Node(parent[i]);
//                 new_parent[parent[i]] = p;
//             }

//             Node* c = new Node(data[i]);

//             if(p->left == NULL){
//                     p->left = c;
//             } else {
//                     p->right = c;
//             }
//         }
//     }
// }

Node* constructTreeDataParent2(vector<int>& data, vector<int>& parent){
    Node* root = NULL;
    Node** nodes = new Node*[101]{NULL};
    // Parsing
    for(int i = 0; i < data.size(); i++){
        Node* node = new Node(data[i]);
        nodes[data[i]] = node;
    }

    // Creating parent - child relations
    for(int i = 0; i < data.size(); i++){
        if(parent[i] != -1){
            Node* child_node = nodes[data[i]];
            Node* parent_node = nodes[parent[i]];

            if(parent_node->left == NULL){
                parent_node->left = child_node;
            } else {
                parent_node->right = child_node;
            }
        } else {
            root = nodes[data[i]];
        }
    }

    return root;
}

// Diameter of tree is the max of all diameters at all nodes
int diameter_On2(Node* root, int* dia){
    if(root == NULL){
        return 0;
    }

    if(root->left == NULL && root->right == NULL){
        return 1;
    }

    int h_left = height(root->left);
    int h_right = height(root->right);

    int p_dia = h_left + h_right + 1;

    (*dia) = (p_dia > (*dia)) ? p_dia : (*dia);
    
    diameter_On2(root->left, dia);
    diameter_On2(root->right, dia);

    return (*dia);
}

int diameter1(Node* root){
    if(root == NULL){
        return 0;
    }
    
    int lh = height(root->left);
    int rh = height(root->right);

    int f1 = lh + rh + 1;
    int f2 = diameter1(root->left);
    int f3 = diameter1(root->right);

    return max(f1, max(f2, f3));
}

// Diameter in O(N)
class DiaPair{
    public:
    int h = 0;
    int d = 0;
};

// Including height in pair reduces my effort to separately find height of the node
DiaPair* diameter2(Node* root){
    if(root == NULL){
        DiaPair* bp = new DiaPair();
        return bp;
    }
    
    DiaPair* lp = diameter2(root->left);
    DiaPair* rp = diameter2(root->right);

    int ht = lp->h + rp->h + 1;

    DiaPair* mp = new DiaPair();

    mp->h = max(lp->h, rp->h) + 1;
    mp->d = max(ht, max(lp->d, rp->d));

    delete lp;
    delete rp;

    return mp;
}

class isBalPair{
    public:
    bool isBal = false;
    int diff = 0;
    // difference of children heights
};

isBalPair* isBalanced(Node* root){
    if(root == NULL){
        isBalPair* bp = new isBalPair();
        bp->isBal = true;
        return bp;
    }

    isBalPair* lp = isBalanced(root->left);
    isBalPair* rp = isBalanced(root->right);
    
    isBalPair* mp = new isBalPair();

    if(lp->isBal && rp->isBal){
        mp->diff = lp->diff + rp->diff;

        if(abs(mp->diff) == 1 || mp->diff == 0){
            mp->isBal = true;
        }   
    }

    return mp;
}

class balPair{
public:
    int height = 0;
    bool isBal = false;
};

balPair* isBalanced2(Node* root){
    if(root == NULL){
        balPair* bp = new balPair();
        bp->isBal = true;
        return bp;
    }
    
    balPair* lp = isBalanced2(root->left);
    balPair* rp = isBalanced2(root->right);

    balPair* mp = new balPair();

    mp->height = max(lp->height, rp->height) + 1;

    if(lp->isBal && rp->isBal && abs(lp->height - rp->height) == 1 || lp->height == rp->height){
        mp->isBal = true;
    }

    return mp;
}

class bst_Pair{
public:
    bool isBST = false;
    int max = INT_MIN;
    int min = INT_MAX;
};

bst_Pair* BST(Node* root){
    if(root == NULL){
        bst_Pair* bp = new bst_Pair();
        bp->isBST = true;
        return bp;
    }
    
    bst_Pair* mp = new bst_Pair();
    
    bst_Pair* lp = BST(root->left);
    
    if(lp->isBST == false){
        mp->isBST = false;
        return mp;
    }
    
    bst_Pair* rp = BST(root->right);

    if(rp->isBST == false){
        mp->isBST = false;
        return mp;
    }

    mp->max = max(root->data, max(lp->max, rp->max));
    mp->min = min(root->data, min(lp->min, rp->min));
    mp->isBST = (lp->max < root->data && rp->min > root->data) ? true : false;

    return mp;
}

class largest_bst_pair{
public:
    bool is_bst = false;
    int max = INT_MIN;
    int min = INT_MAX;
    int lbst_size = 0;
    int lbst_root = -1;
};

largest_bst_pair* largest_bst(Node* root){
    if(root == NULL){
        largest_bst_pair* bp = new largest_bst_pair();
        bp->is_bst = true;
        return bp;
    }
    
    largest_bst_pair* mp = new largest_bst_pair();
    
    largest_bst_pair* lp = largest_bst(root->left);
    
    if(lp->is_bst == false){
        mp->is_bst = false;
        return mp;
    }
    
    largest_bst_pair* rp = largest_bst(root->right);

    if(rp->is_bst == false){
        mp->is_bst = false;
        return mp;
    }

    mp->max = max(root->data, max(lp->max, rp->max));
    mp->min = min(root->data, min(lp->min, rp->min));
    mp->is_bst = (lp->max < root->data && rp->min > root->data) ? true : false;

    if(mp->is_bst == true){
        mp->lbst_root = root->data;
        mp->lbst_size = lp->lbst_size + rp->lbst_size + 1;
    } else {
        if(lp->lbst_size > rp->lbst_size){
            mp->lbst_size = lp->lbst_size;
            mp->lbst_root = lp->lbst_root;
        } else {
            mp->lbst_size = rp->lbst_size;
            mp->lbst_root = rp->lbst_root;
        }
    }

    return mp;
}

int main(int argc, char** argv){
    vector<int> dlist = {
        50, 25, 12, -1, 37, 30, -1, -1, -1, 75, 62, 60, -1, -1, 87, -1, -1, -1
    };

    Node* root = construct(dlist);

    // display(root);

    // cout << size1(root) << endl;
    // cout << size2(root) << endl;
    // cout << size3(root) << endl;
    

    // cout << "-----------------" << endl;

    // cout << height(root) << endl;
    // cout << max(root) << endl;
    // cout << max2(root) << endl;
    // cout << sum(root) << endl;

    // cout << "-----------------" << endl;

    // cout << find(root, 50) << endl;
    // vector<int>* n2rpath = n2rp(root, 30);

    // for(int i = 0; i < n2rpath->size(); i++){
        // cout << n2rpath->at(i) << " ";
    // }

    // cout << endl << "-----------------" << endl;

    // kdown(root, 2);

    vector<int> list1 = {
        1,2,4,6,-1,7,-1,-1,5,8,10,13,17,-1,18,-1,-1,14,-1,-1,11,15,19,22,-1,23,-1,-1,20,-1,-1,16,21,-1,-1,-1,-1,9,12,-1,-1,-1,-1,3,-1,-1
    };

    Node* newRoot = construct(list1);

    // display(newRoot);

    // kDownFromParticularNode(newRoot, 8, 3, 0);

    // printKFar2(newRoot, 11, 3);

    // removeLeaves(root);
    // display(root);
    // cout << endl << "-----------------" << endl;

    // // removeLeaves2(root);
    // display(root);
    // cout << endl << "-----------------" << endl;

    // printSingleChild(root);

    // cout << endl << "-----------------" << endl;

    // int lo = 100, hi = 200, sum = 0;
    // vector<int> path;
    // path2leafInRange(root, lo, hi, sum, path);  
    
    // vector<int> pre = {50, 25, 12, 37, 30, 40, 75, 62, 60, 70, 87, 90};
    // vector<int> in = {12, 25, 30, 37, 40, 50, 60, 62, 70, 75, 87, 90};
    // vector<int> post = {12, 40, 37, 25, 87, 75, 50};
    // vector<int> in2 = {12, 25, 37, 40, 50, 75, 87};

    // Node* root1 = construct1(pre, in, 0, pre.size()-1, 0, in.size()-1);     
    // display(root1); 
    // Node* root2 = construct2(post, in2, 0, post.size()-1, 0, in2.size()-1);      

    vector<int> data = {12, 25, 50, 75, 37, 87, 40};
    vector<int> parent = {25, 50, -1, 50, 25, 75, 37};

    Node* root3 = constructTreeDataParent2(data, parent);
    display(root3);

    // vector<int> pre = {50, 25, 12, 37, 75};
    // vector<int> post = {12, 37, 25, 75, 50};

    // Node* root4 = construct3(pre, post, 0, 4, 0, 4);
    // display(root4);

    // int dia_p = INT_MIN;

    // cout << diameter1(root) << endl;
    // cout << diameter_On2(root, &dia_p) << endl;
    // cout << diameter2(root)->d << endl;

    // cout << isBalanced(root1)->isBal << endl;
    // cout << isBalanced2(root)->isBal << endl;
    // cout << BST(root1)->isBST << endl << BST(root1)->max << endl << BST(root)->min << endl;
    // cout << largest_bst(root1)->lbst_size << endl << largest_bst(root1)->lbst_root << endl;
    // display(root1);
}