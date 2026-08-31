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
    int kthSmallest(TreeNode* root, int k) 
    {
        inorderlist(root);
        return arr[k-1];
    }
    vector<int> arr;
    void inorderlist(TreeNode* root)
    {
        if(root == nullptr) return;
        inorderlist(root->left);
        arr.push_back(root->val);
        inorderlist(root->right);
    }
};
