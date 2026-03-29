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
    TreeNode* invert(TreeNode* root) {
        if (!root)
            return nullptr;
        if (!root->left && !root->right)
            return root;

        auto left = root->left;
        root->left = invert(root->right); 
        root->right = invert(left);   

        return root;
    }
public:
    TreeNode* invertTree(TreeNode* root) {
        return invert(root);   
    }
};
