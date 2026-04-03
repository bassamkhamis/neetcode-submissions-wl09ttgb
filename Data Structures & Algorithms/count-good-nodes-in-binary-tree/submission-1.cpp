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
    int dfs(TreeNode* root, int v) {
        if (!root) 
            return 0; 

        int res{};
        if (root->val >= v)
            res++;

        if (root->left)
            res += dfs(root->left, std::max(root->val, v));
        if (root->right)
            res += dfs(root->right, std::max(root->val, v)); 
            
        return res;       
    }
public:
    int goodNodes(TreeNode* root) {
        return this->dfs(root, INT_MIN);
    }
};
