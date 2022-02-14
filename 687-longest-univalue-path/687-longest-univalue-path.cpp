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
    
    int getHeight(TreeNode* root, int val)
    {
        if(!root || root->val != val)
            return 0;
        
        return 1 + max(getHeight(root->left, val), getHeight(root->right, val));
    }

    int helper(TreeNode* root, int val)
    {
        if(!root || root->val != val)
            return 0;
        
        int l = getHeight(root->left, val);
        
        int r = getHeight(root->right, val);
            
        return max(l+r+1, max(helper(root->left, val), helper(root->right, val)));
        
    }
    
    int longestUnivaluePath(TreeNode* root) {
        
        if(!root)
            return 0;
        
        int ans = helper(root, root->val);
        int ansL = longestUnivaluePath(root->left);
        int ansR = longestUnivaluePath(root->right);
        
        return max(ans-1, max(ansL, ansR));
        
    }
};