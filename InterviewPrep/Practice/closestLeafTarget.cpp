#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

pair<int, int> ans;
void calcMinDist(TreeNode* root, TreeNode* prbt, int d, pair<int, int>& currAns) {
    if (root == NULL || root == prbt) {
        return;
    }
    
    if (root->left == NULL && root->right == NULL) {
        pair<int, int> bres;
        if (d < currAns.second) {
            currAns.second = d;
            currAns.first = root->val;
        }
        return;
    }

    calcMinDist(root->left, prbt, d + 1, currAns);
    calcMinDist(root->right, prbt, d + 1, currAns);
}

vector<TreeNode*> n2rp(TreeNode* root, int key) {
    vector<TreeNode*> mres;

    if (!root) {
        return mres;
    }
    
    if (root->val == key) {
        mres.push_back(root);
        return mres;
    }

    vector<TreeNode*> lres = n2rp(root->left, key);
    if (lres.size() != 0) {
        lres.push_back(root);
        return lres;
    }

    vector<TreeNode*> rres = n2rp(root->right, key);
    if (rres.size() != 0) {
        rres.push_back(root);
        return rres;
    }

    return mres;
}

int findClosestLeaf(TreeNode* root, int k) {
    vector<TreeNode*> n2r = n2rp(root, k);
    int ans;
    int dist = INT_MAX;
    
    for (int i = 0; i < n2r.size(); i++) {
        TreeNode* prbt = (i == 0) ? NULL : n2r[i - 1];
        pair<int, int> currAns = make_pair(0, INT_MAX);
        calcMinDist(n2r[i], prbt, 0, currAns);
        int curr = currAns.first;
        int d = currAns.second + i;
        if (d < dist) {
            dist = d;
            ans = curr;
        }
    }
    
    return ans;
}