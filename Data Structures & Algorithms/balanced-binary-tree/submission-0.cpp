/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * }; */
class Solution 
{
public:
    bool isBalanced(TreeNode* root) 
    {
        if(root == nullptr) return true;
        if( depth(root->left) - depth(root->right) != 0 &&
            depth(root->left) - depth(root->right) != 1 &&
            depth(root->left) - depth(root->right) != -1
        ) return false;
        else return isBalanced(root->left) && isBalanced(root->right);
    }
    int depth(TreeNode* root)
    {
        if(root == nullptr) return 0;
        return 1 + max( depth(root->left) , depth(root->right) );
    }
};
