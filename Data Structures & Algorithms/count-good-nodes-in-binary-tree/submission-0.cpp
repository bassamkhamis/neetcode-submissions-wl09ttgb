/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
    int count{};
    void dfs(TreeNode* root, int v) {
        if (!root) 
            return; 

        if (root->val >= v)
            this->count++;

        if (root->left)
            dfs(root->left, std::max(root->val, v));
        if (root->right)
            dfs(root->right, std::max(root->val, v));    
    }
public:
    int goodNodes(TreeNode* root) {
        this->count = 0;
        this->dfs(root, INT_MIN);

        return this->count;
    }
};
