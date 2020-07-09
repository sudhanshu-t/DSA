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

vector<vector<int>> levelOrderBottom(TreeNode* root) {
    if(root == NULL){
        vector<vector<int>> bres;
        return bres;
    }
    
    vector<vector<int>> res;
    
    vector<vector<int>> leftV = levelOrderBottom(root->left);
    vector<vector<int>> rightV = levelOrderBottom(root->right);
    
    int size = max(leftV.size(), rightV.size());
    int minSize = min(leftV.size(), rightV.size());

    int li = 0, ri = 0;
    
    for(int i = 0; i < size; i++){
        if(i < size - minSize){
            if(leftV.size() > rightV.size()){
                res.push_back(leftV[i]);
                li++;
            } else {
                res.push_back(rightV[i]);            
                ri++;
            }
        } else {
            vector<int> v;

            for(int j = 0; j < leftV[li].size(); j++){
                v.push_back(leftV[li][j]);
            }

            for(int j = 0; j < rightV[ri].size(); j++){
                v.push_back(rightV[ri][j]);
            }

            li++; ri++;
            res.push_back(v);
        }
    }

    vector<int> temp;
    temp.push_back(root->val);
    res.push_back(temp);

    return res;
}

int main(int argc, char** argv){
    vector<int> input = {3,9,20,-1,-1,15,7};

    TreeNode* root = createTree(input);
    // display(root);

    vector<vector<int>> levelOrderResult = levelOrderBottom(root);

    // stackApproach(root);

    for(int i = 0; i < levelOrderResult.size(); i++){
        for(int j = 0; j < levelOrderResult[i].size(); j++){
            cout << levelOrderResult[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}