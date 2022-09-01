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
    int ans;
    
    void helper(TreeNode* root, int maxi)
    {
        if(!root)
            return;
        
        helper(root->left, max(maxi, root->val));
        helper(root->right, max(maxi, root->val));
        
        if(root->val >= maxi)
            ans++;
    }
    
    int goodNodes(TreeNode* root) {
        ans = 0;
        int maxi = -1e5;
        helper(root,maxi);
        return ans;
    }
};