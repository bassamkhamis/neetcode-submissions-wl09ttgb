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
    bool balanced{};
    int length(TreeNode* root) {
        if (!root)
            return 0;

        int left = length(root->left); 
        int right = length(root->right);

        if (abs(left - right) > 1)
            balanced = false;

        return 1 + std::max(left, right);        
    }
public:
    bool isBalanced(TreeNode* root) {
        if (!root)
            return true;

        this->balanced = true;

        length(root);

        return this->balanced;
    }
};
