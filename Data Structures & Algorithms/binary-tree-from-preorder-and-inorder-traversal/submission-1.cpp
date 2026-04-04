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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder,int& idx, int l, int r) {
        if (l > r)
            return nullptr;

        int rootVal = preorder[idx++];
        TreeNode* root = new TreeNode(rootVal);  
        int m = l;
        for (int i = l; i <= r; i++)
            if (rootVal == inorder[i]) {
                m = i;
                break;
            }
  
        root->left = buildTree(preorder, inorder, idx, l, m - 1);
        root->right = buildTree(preorder, inorder, idx, m + 1, r);

        return root;    
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int idx = 0; // by ref to track all nodes laready used, left subtree may use 0,1,2,3... from preorder 
        return buildTree(preorder, inorder, idx, 0, inorder.size() - 1);
    }
};
