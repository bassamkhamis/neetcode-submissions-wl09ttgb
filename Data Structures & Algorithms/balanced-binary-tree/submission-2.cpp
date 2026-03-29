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

    int length2(TreeNode* root) {
        if (!root)
            return 0;

        int left = length2(root->left); 
        if (left == -1)
            return -1;

        int right = length2(root->right);
        if (right == -1)
            return -1;

        if (abs(left - right) > 1)
            return -1;

        return 1 + std::max(left, right);        
    }
public:
    bool isBalanced(TreeNode* root) {
        if (!root)
            return true;
        
        int res = length2(root);
        return res == -1 ? false : true; 

        // method 1
        // this->balanced = true;

        // length(root);

        // return this->balanced;
    }
};
