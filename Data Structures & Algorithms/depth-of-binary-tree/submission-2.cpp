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
    // BFS    
        if (!root)
            return 0;

        queue<TreeNode*> q;
        q.push(root);
        int level{};

        while(!q.empty()) {
            int size = q.size();

            for(int i=0; i < size; i++) {
                auto node = q.front();
                q.pop();

                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }

            level++;
        }

        return level;    
        // DFS iterative
        // stack<pair<TreeNode*, int>> stk;
        // if (!root)
        //     return 0;
   
        // stk.push({root, 1});
        // int maxDepth{};

        // while(!stk.empty()){
        //     auto [cur, depth] = stk.top();
        //     stk.pop();

        //     maxDepth = std::max(maxDepth, depth);

        //     if(cur->left)
        //         stk.push({cur->left, depth + 1});
        //     if (cur->right) 
        //         stk.push({cur->right, depth + 1});   
        // }  

        // return maxDepth;  

        // DFS recursive
        // if (!root)
        //     return 0;

        // int l = 1 + maxDepth(root->left); 
        // int r = 1 + maxDepth(root->right);

        // return std::max(l, r);   
    }
};
