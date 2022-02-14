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
    
    int helper(TreeNode* &root)
    {
        if(!root)
            return 0;
        
        int l = helper(root->left);
        int r = helper(root->right);
        int val = root->val;
        
        if(l+r+val == 0)
        {
            root = NULL;
        }
        
        return l+r+val;
    }
    
    TreeNode* pruneTree(TreeNode* root) {
        
        TreeNode* ans = new TreeNode(1);
        ans->right = root;
        helper(ans);
        return ans->right;
    }
};