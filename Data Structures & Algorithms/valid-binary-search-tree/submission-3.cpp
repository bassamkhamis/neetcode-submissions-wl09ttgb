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
private:    
    bool isValidBST(TreeNode* root, long long min, long long max) {
        if (!root)
            return true; 

        if (min >= root->val || max <= root->val)
            return false;

        return isValidBST(root->left, min, root->val) && isValidBST(root->right, root->val, max);         
    }
public:
    bool isValidBST(TreeNode* root) {
        if (!root)
            return true;

        return isValidBST(root, LLONG_MIN, LLONG_MAX);
    }
};
