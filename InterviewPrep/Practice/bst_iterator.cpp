#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator {
private:
    class cell{
    public:
        TreeNode* root;
        int state;
        
        cell(TreeNode* r, int s){
            root = r;
            state = s;
        }
    };
    
    stack<cell> st;
    
public:
    BSTIterator(TreeNode* root) {
        
    }
    
    /** @return the next smallest number */
    int next() {
        
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        
    }
};