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
    vector<int> inorder;
    int dfs(TreeNode* root, int& visit, int k) {
        if (!root)
            return -1; // not found

       int res = dfs(root->left, visit, k);
       if (res != -1) return res;

        visit++;
        if (visit == k)
            return root->val;  

        return dfs(root->right, visit, k);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int v=0;
        return dfs(root, v, k);
    }
};
