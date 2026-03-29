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
public:
    int maxDepth(TreeNode* root) {
        if (!root)
            return 0;

        stack<pair<TreeNode*, int>> stk;
        stk.push({root, 1});
        int maxDepth{};

        while(!stk.empty()){
            auto [cur, depth] = stk.top();
            stk.pop();

            maxDepth = std::max(maxDepth, depth);

            if(cur->left)
                stk.push({cur->left, depth + 1});
            if (cur->right) 
                stk.push({cur->right, depth + 1});   
        }  

        return maxDepth;  

        // if (!root)
        //     return 0;

        // int l = 1 + maxDepth(root->left); 
        // int r = 1 + maxDepth(root->right);

        // return std::max(l, r);   
    }
};
