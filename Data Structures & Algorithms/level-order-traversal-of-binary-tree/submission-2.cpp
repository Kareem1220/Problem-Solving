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
    vector<vector<int>> levelOrder(TreeNode* root) 
    { 
        std::vector<vector<int>> sol;
        std::vector<int> layer;
        if(root == nullptr) return {}; 

        std::queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int level = q.size();
            for(int i = 0 ; i < level ; i++)
            {
                TreeNode* current = q.front();
                q.pop();
                layer.push_back(current->val);
                if(current->left != nullptr) q.push(current->left);
                if(current->right != nullptr) q.push(current->right);
            }
            sol.push_back(layer);
            layer.clear();
        }
        return sol;
    }
};
