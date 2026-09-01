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
    int diameterOfBinaryTree(TreeNode* root) 
    {
        return max(diameter(root) , max(diameter(root->left) , diameter(root->right)));
    }
    int depth(TreeNode* root)
    {
        if(root == nullptr) return 0;
        return 1 + max(depth(root->left) , depth(root->right));
    }
    int diameter(TreeNode* root)
    {
        if(root == nullptr) return 0;
        return depth(root->left) + depth(root->right);
    }
};
