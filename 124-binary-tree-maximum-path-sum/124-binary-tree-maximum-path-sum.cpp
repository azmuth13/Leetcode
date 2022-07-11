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
    
    int ans = INT_MIN;
    
    int max_gain(TreeNode *root){
        
        if(!root)
            return 0;
        
        int l = max(0, max_gain(root->left));
        
        int r = max(0, max_gain(root->right));
        
        int temp = l + r + root->val;
        
        ans = max(ans, temp);
        return (root->val + max(l,r));
        
    }
    
    int maxPathSum(TreeNode* root) {
        
        max_gain(root);

        return ans;
    }
};