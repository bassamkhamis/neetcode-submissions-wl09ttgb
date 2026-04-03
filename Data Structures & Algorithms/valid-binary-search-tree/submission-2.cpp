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
    bool isValidBST(TreeNode* root, int min, int max) {
        if (!root)
            return true; 

        if (min < root->val && max > root->val)
            return  isValidBST(root->left, min, root->val) && isValidBST(root->right, root->val, max);

        return false;          
    }
public:
    bool isValidBST(TreeNode* root) {
        if (!root)
            return true;

        return isValidBST(root, INT_MIN, INT_MAX);
    }
};
