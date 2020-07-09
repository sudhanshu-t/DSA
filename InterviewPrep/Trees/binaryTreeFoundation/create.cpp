// toDuplicate, fromDuplicate, toLL, fromLL, DLL same
// delete root in removeleaves1
// post pre construct

#include <iostream>
#include <vector>
#include <stack>
#include <climits>

using namespace std;

class TreeNode{
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data){
        left = NULL;
        right = NULL;
        this->data = data;
    }
};

TreeNode* construct(vector<int>& dlist){
    vector<TreeNode*> nlist (dlist.size());
    nlist[0] = new TreeNode(dlist[0]);
    
    for(int i = 1; i < dlist.size(); i++){
        if(dlist[i] != -1){
            int pi = (i - 1) / 2;

            cout << "Parent " << nlist[pi]->data << endl;

            TreeNode* parentNode = nlist[pi];
            TreeNode* childNode = new TreeNode(dlist[i]);

            if(i == 2 * pi + 1){
                parentNode->left = childNode;
            } else {
                parentNode->right = childNode;
            }

            nlist[i] = childNode;
        }
    }

    return nlist[0];
}

TreeNode* construct2(vector<int>& dlist){
    stack<TreeNode*> st;

    TreeNode* root = NULL;

    for(int i = 0; i < dlist.size(); i++){
        TreeNode* nn = new TreeNode(dlist[i]);

        if(dlist[i] != -1){
            if(st.size() == 0){
                root = nn;
            } else {
                TreeNode* parent = st.top();

                if(parent->left == NULL){
                    parent->left = nn;
                } else {
                    parent->right = nn;
                }
            }

            st.push(nn);
        } else {
            st.pop();
        }
    }

    return root;
}

TreeNode* construct3(vector<int>& dlist){
    stack<TreeNode*> st;
    TreeNode* root = new TreeNode(dlist[0]);
    st.push(root);

    for(int i = 1; i < dlist.size(); i++){
        if(dlist[i] != -1){
            TreeNode* nn = new TreeNode(dlist[i]);
            st.push(nn);
        } else {
            TreeNode* nn = st.top();
            st.pop();

            if(st.size() != 0){
                TreeNode* parent = st.top();
                st.pop();

                if(parent->left == NULL){
                    parent->left = nn;
                } else {
                    parent->right = nn;
                }

                st.push(parent);
            }
        }
    }

    return root;
}

void display(TreeNode* root){
    if(root == NULL){
        return;
    }

    string s = "";

    s += (root->left != NULL) ? to_string(root->left->data) : " .";
    s += " <= " + to_string(root->data) + " => ";
    s += (root->right != NULL) ? to_string(root->right->data) : ". ";

    cout << s << endl;

    display(root->left);
    display(root->right);
}

int size(TreeNode* root){
    if(root == NULL){
        return 0;
    }
    
    int ls = size(root->left);
    int rs = size(root->right);

    return ls + rs + 1;
}

int height(TreeNode* root){
    if(root == NULL){
        return 0;
    }
    
    int lh = height(root->left);
    int rh = height(root->right);

    return max(lh, rh) + 1;
}

int maxV(TreeNode* root){
    if(root == NULL){
        return INT_MIN;
    }
    
    int ml = maxV(root->left);
    int mr = maxV(root->right);

    return max(root->data, max(ml, mr));
    cout << height(root) << endl;
    cout << height(root) << endl;
}

int minV(TreeNode* root){
    if(root == NULL){
        return INT_MAX;
    }
    
    int ml = minV(root->left);
    int mr = minV(root->right);

    return min(root->data, min(ml, mr));
}

int sum(TreeNode* root){
    if(root == NULL){
        return 0;
    }
    
    int ls = sum(root->left);
    int rs = sum(root->right);

    return ls + rs + root->data;
}

bool find(TreeNode* root, int key){
    if(root == NULL){
        return false;
    }
    
    if(root->data == key){
        return true;
    }
    
    bool lf = find(root->left, key);
    if(lf){
        return true;
    }

    bool rf = find(root->right, key);
    if(rf){
        return true;
    }

    return false;
}

vector<TreeNode*>* n2rp(TreeNode* root, int key){
    if(root == NULL){
        return NULL;
    }
    
    vector<TreeNode*>* res = new vector<TreeNode*>();

    if(root->data == key){
        res->push_back(root);
        return res;
    }

    vector<TreeNode*>* lPath = n2rp(root->left, key);
    if(lPath != NULL){
        lPath->push_back(root);
        return lPath;
    }
    
    vector<TreeNode*>* rPath = n2rp(root->right, key);
    if(rPath != NULL){
        rPath->push_back(root);
        return rPath;
    }

    return NULL;
}

void kDown(TreeNode* root, int k){
    if(root == NULL){
        return;
    }

    if(k == 0){
        cout << root->data << endl;
        return;
    }

    kDown(root->left, k - 1);
    kDown(root->right, k - 1);
}

void kDownFromNode(TreeNode* root, int d, int k, int state){
    if(root == NULL){
        return;
    }

    if(state == 0){
        if(root->data == d){
            kDownFromNode(root->left, d, k-1, state+1);
            kDownFromNode(root->right, d, k-1, state+1);
        } else {
            kDownFromNode(root->left, d, k, state);
            kDownFromNode(root->right, d, k, state);
        }
    } else {
        if(k == 0){
            cout << root->data << endl;
            return;
        }

        kDownFromNode(root->left, d, k-1, state);
        kDownFromNode(root->right, d, k-1, state);
    }
}

void kFarSlave(TreeNode* root, TreeNode* prohibited, int k){
    if(root == NULL || root == prohibited){
        return;
    }
    
    if(k == 0){
        cout << root->data << endl;
        return;
    }

    kFarSlave(root->left, prohibited, k - 1);
    kFarSlave(root->right, prohibited, k - 1);
}

void kFarMaster(TreeNode* root, int data, int k){
    vector<TreeNode*>* n2rpath = n2rp(root, data);

    for(int i = 0; i < n2rpath->size() && k - i >= 0; i++){
        TreeNode* prohibited = NULL;

        if(i > 0){
            prohibited = (*n2rpath)[i-1];
        }

        kFarSlave((*n2rpath)[i], prohibited, k - i);
    }
}

// A little less memory inefficient when root is itself the leaf node
void removeLeaves(TreeNode*& root){
    if(root->left == NULL && root->right == NULL){
        // (*root);
        root = NULL;
        // delete root;
        return;
    }

    if(root->left != NULL){
        if(root->left->left == NULL && root->left->right == NULL){
            TreeNode* temp = root->left;
            root->left = NULL;
            delete temp;
        } else {
            removeLeaves(root->left);
        }
    }

    if(root->right != NULL){
        if(root->right->left == NULL && root->right->right == NULL){
            TreeNode* temp = root->right;
            root->right = NULL;
            delete temp;
        } else {
            removeLeaves(root->right);
        }
    }
}

TreeNode* removeLeaves2(TreeNode* root){
    if(root->left == NULL && root->right == NULL){
        delete root;
        return NULL;
    }

    root->left = removeLeaves2(root->left);
    root->right = removeLeaves2(root->right);

    return root;
}

void printSingleChild(TreeNode* root){
    if(root->left != NULL && root->right != NULL){
        printSingleChild(root->left);
        printSingleChild(root->right);
    } else if(root->left != NULL){
        cout << root->left->data << endl;
        printSingleChild(root->left);
    } else if(root->right != NULL){
        cout << root->right->data << endl;
        printSingleChild(root->right);
    } else {
        return;
    }
}

void n2lInRange(TreeNode* root, int lo, int hi, int sum, vector<int>& path){
    if(root == NULL){
        return;
    }
    
    if(root->left == NULL && root->right == NULL){
        sum += root->data;
        path.push_back(root->data);
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
    n2lInRange(root->left, lo, hi, sum + root->data, path);
    n2lInRange(root->right, lo, hi, sum + root->data, path);
    path.pop_back();
}

TreeNode* preInConstruct(vector<int>& pre, vector<int>& in, int ps, int pe, int is, int ie){
    if(ps > pe || is > ie){
        return NULL;
    }

    int rootData = pre[ps];
    int leftSize = 0;
    for(int i = is; i <= ie; i++){
        if(in[i] == rootData){
            break;
        }
        leftSize++;
    }

    TreeNode* root = new TreeNode(rootData);

    root->left = preInConstruct(pre, in, ps + 1, ps + leftSize, is, is + leftSize - 1);
    root->right = preInConstruct(pre, in, ps + leftSize + 1, pe, is + leftSize + 1, ie);

    return root;
}

TreeNode* postInConstruct(vector<int>& post, vector<int>& in, int ps, int pe, int is, int ie){
    if(ps > pe || is > ie){
        return NULL;
    }

    TreeNode* root = new TreeNode(post[pe]);

    int leftSize = 0;
    for(int i = is; i <= ie; i++){
        if(in[i] == post[pe]){
            break;
        }
        leftSize++;
    }

    root->left = postInConstruct(post, in, ps, ps + leftSize - 1, is, is + leftSize - 1);
    root->right = postInConstruct(post, in, ps + leftSize, pe - 1, is + leftSize + 1, ie);

    return root;
}

TreeNode* postPreConstruct(vector<int>& post, vector<int>& pre, int postLo, int postHi, int preLo, int preHi){
    if(postLo > postHi || preLo > preHi){
        return NULL;
    }

    TreeNode* root = new TreeNode(pre[preLo]);

    int leftSize = 0;
    for(int i = postLo; i <= postHi; i++){
        if(post[i] == pre[preLo + 1]){
            break;
        }
        leftSize++;
    }

    cout << root->data << " " << leftSize << endl;

    root->left = postPreConstruct(post, pre, postLo, postLo + leftSize, preLo + 1, preLo + leftSize + 1);
    cout << root->data << " in" << endl;
    root->right = postPreConstruct(post, pre, postLo + leftSize + 1, postHi - 1, preLo + leftSize + 2, preHi);

    return root;
}

TreeNode* parentChild(vector<int>& children, vector<int>& parent){
    TreeNode** nodesArray = new TreeNode*[101]{NULL};
    TreeNode* root = NULL;

    for(int i = 0; i < children.size(); i++){
        TreeNode* node = new TreeNode(children[i]);
        nodesArray[children[i]] = node;
    }

    for(int i = 0; i < children.size(); i++){
        if(parent[i] != -1){
            TreeNode* childNode = nodesArray[children[i]];
            TreeNode* parentNode = nodesArray[parent[i]];

            if(parentNode->left == NULL){
                parentNode->left = childNode;
            } else {
                parentNode->right = childNode;
            }
        } else {
            root = nodesArray[children[i]];
        }
    }

    return root;
}

class DiameterHelper{
public:
    int height;
    int diameter;

    DiameterHelper(int d, int h){
        diameter = d;
        height = h;
    }
};

DiameterHelper* diameter(TreeNode* root){
    if(root == NULL){
        DiameterHelper* bres = new DiameterHelper(0, 0);
        return bres;
    }

    // if(root->left == NULL && root->right == NULL){
    //     DiameterHelper* bres = new DiameterHelper(1, 1);
    //     return bres;
    // }

    DiameterHelper* leftPair = diameter(root->left);
    DiameterHelper* rightPair = diameter(root->right);

    int myHeight = max(leftPair->height, rightPair->height) + 1;
    int myDiameter = max(leftPair->height + rightPair->height + 1,
                     max(leftPair->diameter, rightPair->diameter));

    delete leftPair;
    delete rightPair;

    DiameterHelper* res = new DiameterHelper(myDiameter, myHeight);
    return res;
}

class BalancedHelper{
public:
    int height;
    bool isBal;

    BalancedHelper(int h, bool b){
        isBal = b;
        height = h;
    }
};

BalancedHelper* isBalanced(TreeNode* root){
    if(root == NULL){
        BalancedHelper* bres = new BalancedHelper(0, true);
        return bres;
    }

    BalancedHelper* leftSubtree = isBalanced(root->left);
    BalancedHelper* rightSubtree = isBalanced(root->right);

    int myHeight = max(leftSubtree->height, rightSubtree->height) + 1;
    bool amIBal = false;
    BalancedHelper* myResult = new BalancedHelper(myHeight, amIBal);

    if(leftSubtree->isBal == false || rightSubtree->isBal == false){
        return myResult;
    }

    if(abs(leftSubtree->height - rightSubtree->height) > 1){
        return myResult;
    }

    delete leftSubtree;
    delete rightSubtree;

    myResult->isBal = true;
    return myResult;
}

class BSThelper{
public:
    bool isBst = false;
    int max = INT_MIN;
    int min = INT_MAX;
};

BSThelper* isBST(TreeNode* root){
    if(root == NULL){
        BSThelper* bp = new BSThelper();
        bp->isBst = true;

        return bp;
    }

    BSThelper* mp = new BSThelper();
    
    BSThelper* lp = isBST(root->left);
    if(!lp->isBst){
        return mp;
    }
    
    BSThelper* rp = isBST(root->right);
    if(!rp->isBst){
        return mp;
    }

    mp->max = max(root->data, max(lp->max, rp->max));
    mp->min = min(root->data, min(lp->min, rp->min));
    mp->isBst = (root->data >= lp->max && root->data <= rp->min)?true:false;

    delete lp;
    delete rp;

    return mp;
}

class LargestHelper{
public:
    bool isBst = false;
    int max = INT_MIN;
    int min = INT_MAX;
    int sizeLargestBst = 0;
    int dataLargestBst = -1;
};

LargestHelper* largestBst(TreeNode* root){
    if(root == NULL){
        LargestHelper* bp = new LargestHelper();
        bp->isBst = true;
        return bp;
    }
    
    LargestHelper* lp = largestBst(root->left);
    LargestHelper* rp = largestBst(root->right);

    LargestHelper* mp = new LargestHelper();

    mp->max = max(root->data, max(lp->max, rp->max));
    mp->min = min(root->data, min(lp->min, rp->min));


    if(lp->isBst == false || rp->isBst == false){
        if(lp->sizeLargestBst >= rp->sizeLargestBst){
            mp->dataLargestBst = lp->dataLargestBst;
            mp->sizeLargestBst = lp->sizeLargestBst;
        } else {
            mp->dataLargestBst = rp->dataLargestBst;
            mp->sizeLargestBst = rp->sizeLargestBst;
        }

        return mp;
    }

    mp->isBst = (rp->min >= root->data && lp->max <= root->data)?true:false;
    mp->dataLargestBst = (mp->isBst == true) ? root->data : ((lp->sizeLargestBst >= rp->sizeLargestBst) ? lp->dataLargestBst : rp->dataLargestBst);
    mp->sizeLargestBst = (mp->isBst == true) ? lp->sizeLargestBst + rp->sizeLargestBst + 1 : ((lp->sizeLargestBst >= rp->sizeLargestBst) ? lp->dataLargestBst : rp->dataLargestBst);

    delete lp;
    delete rp;

    return mp;
}

// TreeNode *pred = NULL, *succ = NULL;
void predSucc(TreeNode*& root, int& succ, int& pred, int& state, int key){
    if(root == NULL){
        return;
    }

    if(state == 0){
        if(root->data != key){
            pred = root->data;
        } else {
            state = 1;
        }
    } else if(state == 1){
        succ = root->data;
        state++;
        return;
    }

    cout << pred << " " << succ << endl;

    predSucc(root->left, succ, pred, state, key);
    predSucc(root->right, succ, pred, state, key);

}

void threadedTree(TreeNode*& root, int& succ, int& pred, int& state, int key){
    if(root == NULL){
        return;
    }

    threadedTree(root->left, succ, pred, state, key);
    if(state == 0){
        if(root->data != key){
            pred = root->data;
        } else {
            state = 1;
        }
    } else if(state == 1){
        succ = root->data;
        state++;
        return;
    }

    cout << pred << " " << succ << endl;

    threadedTree(root->right, succ, pred, state, key);

}

void inorder(TreeNode* root){
    if(root == NULL){
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

TreeNode* rightMost(TreeNode* root, TreeNode* parent){
    while(root->right && root->right != parent){
        root = root->right;
    }

    return root;
}

void morris(TreeNode* root){
    while(root){

        if(root->left != NULL){
            TreeNode* lrm = rightMost(root->left, root);

            if(lrm->right == NULL){
                lrm->right = root;
                root = root->left;
            } else {
                lrm->right = NULL;
                cout << root->data << " ";
                root = root->right;
            }
        } else {
            cout << root->data << " ";
            root = root->right;
        }
    }
}

int main(int agrc, char** argv){
    vector<int> dlist = {
        50, 25, 12, -1, 37, 30, -1, 40, -1, -1, -1, 75, 62, 60, -1, 70, -1, -1, 87, -1, -1, -1
    };

    TreeNode* root = construct3(dlist);
    display(root);

    // cout << size(root) << endl;
    // cout << height(root) << endl;
    // cout << maxV(root) << endl;
    // cout << minV(root) << endl;
    // cout << sum(root) << endl;
    // cout << find(root, 71) << endl;

    // vector<TreeNode*>* path = n2rp(root, 30);
    // for(int i = 0; i < path->size(); i++){
    //     cout << (*path)[i]->data << " ";
    // }
    // cout << endl;

    // kDown(root, 2);
    // kDownFromNode(root, 37, 1, 0);

    // vector<int> list1 = {
    //     1,2,4,6,-1,7,-1,-1,5,8,10,13,17,-1,18,-1,-1,14,-1,-1,11,15,19,22,-1,23,-1,-1,20,-1,-1,16,21,-1,-1,-1,-1,9,12,-1,-1,-1,-1,3,-1,-1
    // };

    // TreeNode* root2 = construct3(list1);
    // display(root2);
    // kFarMaster(root2, 11, 3);

    // vector<int> dlist2 = {100};
    // root = construct3(dlist2);
    // removeLeaves(root);

    // root = removeLeaves2(root);
    // cout << root->left->data << endl;
    // display(root);

    // printSingleChild(root);

    // int lo = 100, hi = 200, sum = 0;
    // vector<int> path;
    // n2lInRange(root, lo, hi, sum, path);

    // vector<int> pre = {50, 25, 12, 37, 30, 40, 75, 62, 60, 70, 87, 90};
    // vector<int> in = {12, 25, 30, 37, 40, 50, 60, 62, 70, 75, 87, 90};
    // TreeNode* root1 = preInConstruct(pre, in, 0, pre.size() - 1, 0, in.size() - 1);
    // display(root1);

    // vector<int> post = {12, 40, 37, 25, 87, 75, 50};
    // vector<int> in2 = {12, 25, 37, 40, 50, 75, 87};
    // TreeNode* root1 = postInConstruct(post, in2, 0, post.size() - 1, 0, in2.size() - 1);
    // display(root1);

    // vector<int> pre = {50, 25, 12, 37, 75};
    // vector<int> post = {12, 37, 25, 75, 50};
    // TreeNode* root1 = postPreConstruct(post, pre, 0, post.size() - 1, 0, pre.size() - 1);
    // display(root1);

    // vector<int> data = {12, 25, 50, 75, 37, 87, 40};
    // vector<int> parent = {25, 50, -1, 50, 25, 75, 37};

    // TreeNode* root3 = parentChild(data, parent);
    // display(root3);

    // DiameterHelper* diaPair = diameter(root);
    // cout << diaPair->diameter << endl;

    // BalancedHelper* balPair = isBalanced(root);
    // cout << balPair->isBal << endl;
    // cout << balPair->height << endl;

    // cout << isBST(root1)->isBst << endl;
    // cout << isBST(root1)->max << endl;
    // cout << isBST(root1)->min << endl;

    // cout << largestBst(root1)->dataLargestBst << endl;
    // cout << largestBst(root1)->sizeLargestBst << endl;

    // int pred, succ, state = 0;
    // predSucc(root, succ, pred, state, 37);
    // cout << endl;
    // cout << succ << " " << pred << endl;

    // inorder(root);

    morris(root);
}