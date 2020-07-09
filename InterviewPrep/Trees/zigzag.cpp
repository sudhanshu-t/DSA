#include <iostream>
#include <vector>
#include <queue>
#include <list>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void display(TreeNode* root){
    if(root == NULL){
        return;
    }

    string s = "";

    s += (root->left != NULL) ? to_string(root->left->val) : " .";
    s += " <- " + to_string(root->val) + " -> ";
    s += (root->right != NULL) ? to_string(root->right->val) : ". ";

    cout << s << endl;

    display(root->left);
    display(root->right);
}

TreeNode* createTree(vector<int>& input){
    TreeNode* root = new TreeNode(input[0]);

    vector<TreeNode*> nodes (input.size());
    nodes[0] = root;
    
    for(int i = 1; i < input.size(); i++){
        if(input[i] != -1){
            TreeNode* nn = new TreeNode(input[i]);

            int pi = (i - 1) / 2;
            if(i == 2 * pi + 1){
                nodes[pi]->left = nn;
            } else {
                nodes[pi]->right = nn;
            }

            // cout << input[i] << " child of " << input[pi] << endl;

            nodes[i] = nn;
        }
    }

    return root;
}

vector<vector<int>> stackApproach(TreeNode* root){
    vector<vector<int>> res;
    
    list<TreeNode*>* curr = new list<TreeNode*>();
    list<TreeNode*>* next = new list<TreeNode*>();

    curr->push_front(root);

    vector<list<TreeNode*>> resList;
    list<TreeNode*> resChild;

    bool l2r = true;

    while(curr->size() != 0){
        TreeNode* rem = curr->front();
        curr->pop_front();

        // cout << rem->val << " ";
        resChild.push_back(rem);

        if(l2r == true){
            if(rem->left != NULL)
                next->push_front(rem->left);
            if(rem->right != NULL){
                next->push_front(rem->right);
            }
        } else {
            if(rem->right != NULL){
                next->push_front(rem->right);
            }
            if(rem->left != NULL)
                next->push_front(rem->left);
        }

        if(curr->size() == 0){
            // cout << endl;
            l2r = !l2r;

            resList.push_back(resChild);

            resChild.clear();

            list<TreeNode*>* temp = curr;
            curr = next;
            next = new list<TreeNode*>();

            delete temp;
        }
    }

    for(int i = 0; i < resList.size(); i++){
        vector<int> temp;

        while(resList[i].size()){
            temp.push_back(resList[i].front()->val);
            resList[i].pop_front();
        }

        res.push_back(temp);
    }

    return res;
}

int main(int argc, char** argv){
    vector<int> input = {3,9,20,-20,10,15,7};

    TreeNode* root = createTree(input);
    // display(root);

    vector<vector<int>> levelOrderResult = stackApproach(root);;

    // stackApproach(root);

    for(int i = 0; i < levelOrderResult.size(); i++){
        for(int j = 0; j < levelOrderResult[i].size(); j++){
            cout << levelOrderResult[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}