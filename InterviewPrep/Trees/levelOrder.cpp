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

// Delimiter Approach
vector<vector<int>> levelOrder(TreeNode* root) {
    queue<TreeNode*> q;
    vector<vector<int>> res;
    q.push(root);
    q.push(NULL);
    
    vector<int> currLevel;
    while(q.size() > 0){
        TreeNode* front = q.front();
        q.pop();
        
        if(front != NULL){
            // cout << front->val << " ";
            currLevel.push_back(front->val);
        } else {
            // cout << endl;
            res.push_back(currLevel);
            currLevel.clear();

            if(q.size() != 0){
                q.push(NULL);
            }

            continue;
        }
                
        if(front->left != NULL)
            q.push(front->left);
        if(front->right != NULL)
            q.push(front->right);
    }
    
    return res;
}

class Pair{
public:
    TreeNode* node;
    int level;

    Pair(TreeNode* node, int level){
        this->node = node;
        this->level = level;
    }
};

vector<vector<int>> pairApproach(TreeNode* root){
    list<Pair> q;
    vector<int> currLevel;
    vector<vector<int>> res;

    q.push_back(Pair (root, 1));

    int prevLevel = 1;

    while(q.size() != 0){
        Pair front = q.front();
        q.pop_front();

        if(front.level != prevLevel){
            prevLevel = front.level;
            res.push_back(currLevel);
            currLevel.clear();
            currLevel.push_back(front.node->val);
        } else {
            currLevel.push_back(front.node->val);
        }

        if(front.node->left != NULL){
            q.push_back(Pair (front.node->left, front.level + 1));
        }

        if(front.node->right != NULL){
            q.push_back(Pair (front.node->right, front.level + 1));
        }
    }

    res.push_back(currLevel);
    return res;
}

void stackApproach(TreeNode* root){
    vector<vector<int>> res;
    
    list<TreeNode*>* curr = new list<TreeNode*>();
    list<TreeNode*>* next = new list<TreeNode*>();

    curr->push_front(root);

    while(curr->size() != 0){
        TreeNode* rem = curr->front();
        curr->pop_front();

        cout << rem->val << " ";

        if(rem->left != NULL)
            next->push_front(rem->left);
        if(rem->right != NULL){
            next->push_front(rem->right);
        }

        if(curr->size() == 0){
            cout << endl;

            list<TreeNode*>* temp = curr;
            curr = next;
            next = new list<TreeNode*>();

            delete temp;
        }
    }
}

int main(int argc, char** argv){
    vector<int> input = {3,9,20,-1,-1,15,7};

    TreeNode* root = createTree(input);
    // display(root);

    // vector<vector<int>> levelOrderResult = pairApproach(root);

    stackApproach(root);

    // for(int i = 0; i < levelOrderResult.size(); i++){
    //     for(int j = 0; j < levelOrderResult[i].size(); j++){
    //         cout << levelOrderResult[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    return 0;
}