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
    string serialize(TreeNode* root) {
        if (root == nullptr)
            return "$#";

        return "$" + to_string(root->val) + serialize(root->left) + 
            serialize(root->right);    
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root && !subRoot)
            return true;

        string serialized_root = serialize(root);
        string serialized_subRoot = serialize(subRoot);
        if (serialized_root.find(serialized_subRoot) != std::string::npos)
            return true;
        else 
            return false;
    }
};
