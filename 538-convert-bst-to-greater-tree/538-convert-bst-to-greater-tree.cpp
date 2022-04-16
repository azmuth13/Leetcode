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
    
    void helper(TreeNode* root, int &parentSum)
    {
        if(!root)
            return;
        
        helper(root->right, parentSum);
        root->val += parentSum;
        parentSum = root->val;
        helper(root->left, parentSum);
        
    }
    
    TreeNode* convertBST(TreeNode* root) {
        int p = 0;
        helper(root, p);
        return root;
    }
};