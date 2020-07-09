// toDuplicate, fromDuplicate, toLL, fromLL, DLL same
// delete root in removeleaves1
// post pre construct

#include <iostream>
#include <vector>
#include <stack>
#include <climits>
#include <algorithm>

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

void inorder(TreeNode* root, vector<int>& A){
    if(root == NULL){
        return;
    }

    inorder(root->left, A);
    A.push_back(root->data);
    inorder(root->right, A);
}

TreeNode* rightMost(TreeNode* root){
    TreeNode* temp = root;
    while(temp->right != NULL){
        temp = temp->right;
    }

    return temp;
}

void morrisTraversal(TreeNode* root){
    while(root != NULL){
        cout << root->data << " ";

        if(root->left != NULL){
            TreeNode* lrm = rightMost(root->left);
            // cout << lrm->data << endl;
            if(lrm->right == NULL){
                lrm->right = root;
                root = root->left;
            } else {
                lrm->right = NULL;
                // cout << root->data << " ";
                root = root->right;
            }
        } else {
            cout << root->data << " ";
            root = root->right;
            // cout << root->data << " ";

        }
    }
}

void print(const vector<int>& A){
    for(int i = 0; i < A.size(); i++){
        cout << A[i] << " ";
    }
    cout << endl;
}

void inorderVector(vector<int>& A, vector<int>& V, int index){
    if(index >= A.size()){
        return;
    }

    inorderVector(A, V, 2 * index + 1);
    V.push_back(A[index]);
    inorderVector(A, V, 2 * index + 2);
}

int minSwaps(vector<int>& arr){
    vector<pair<int, int>> T (arr.size());
    for(int i = 0; i < T.size(); i++){
        T[i].first = arr[i];
        T[i].second = i;
    }

    sort(T.begin(), T.end());

    for(int i = 0; i < T.size(); i++){
        cout << T[i].first << " ";
    }
    cout << endl;

    int count = 0;
    for(int i = 0; i < T.size(); i++){
        if(T[i].second == i){
            continue;
        } else {
            swap(T[i].first, T[T[i].second].first);
            swap(T[i].second, T[T[i].second].second);
            count++;
        }

        if(i != T[i].second){
            i--;
        }
    }

    return count;
}

int main(int agrc, char** argv){
    vector<int> dlist = {
        50, 25, 12, -1, 37, 30, -1, 40, -1, -1, -1, 75, 62, 60, -1, 70, -1, -1, 87, -1, -1, -1
    };

    TreeNode* root = construct3(dlist);
    
    vector<int> A;
    inorder(root, A);

    print(A);

    vector<int> V;
    inorderVector(A, V, 0);

    print(V);

    vector<int> test = {10,2,3,14,6};
    cout << minSwaps(test) << endl;

    morrisTraversal(root);
}