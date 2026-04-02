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
     bool isSameTree(TreeNode* p, TreeNode* q) {
        // Iterative DFS
        stack<pair<TreeNode*, TreeNode*>> stk;
        stk.push({p, q});

        while (!stk.empty()) {
            auto [node1, node2] = stk.top();
            stk.pop();

            if (!node1 && !node2)
                continue;

            if (!node1 || !node2 || node1->val != node2->val)
                return false;

            stk.push({node1->right, node2->right}); 
            stk.push({node1->left, node2->left});   

        }

        return true;
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root && !subRoot)
            return true;

        // Iterative DFS
        stack<TreeNode*> stk;
        stk.push(root);

        while (!stk.empty()) {
            auto node = stk.top();
            stk.pop();

            if (isSameTree(node, subRoot))
                return true;

            if (node->right)    
                stk.push(node->right); 

            if (node->left)    
                stk.push(node->left); 
        }

        return false; 
    }
};
