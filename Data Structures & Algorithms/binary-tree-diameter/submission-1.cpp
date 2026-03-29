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
    }
    int max_height(TreeNode* root) {
        if (!root)
            return 0;

        int left = max_height(root->left);  
        int right = max_height(root->right); 

        dim = std::max(dim, left + right);
        return std::max(left, right) + 1;    
    }
public:
    int dim{};
    int diameterOfBinaryTree(TreeNode* root) {

        max_height(root);
        return dim;
        // if (!root)
        //     return 0;
            
        // stack<TreeNode*> stk;
        // int maxDia{};

        // stk.push(root);

        // while(!stk.empty()) {
        //     auto cur = stk.top();
        //     stk.pop();

        //     int left{}, right{};

        //     if(cur->left) {
        //         stk.push(cur->left);
        //         left = maxDepth(cur->left);
        //     }
        //     if (cur->right) {
        //         stk.push(cur->right); 
        //         right = maxDepth(cur->right);
        //     }

        //     maxDia = std::max(maxDia, left + right);      
        // }  

        // return maxDia; 
    }
};
