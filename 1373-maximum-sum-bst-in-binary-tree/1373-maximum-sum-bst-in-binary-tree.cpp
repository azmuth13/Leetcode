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
        
    vector <int> helper(TreeNode* root)
    {
        if(!root)
        {
            // sum, minimum, maximum, flag (isBst)
            return {0,(int)-1e9,(int)1e9,1};
        }
        
        vector <int> left = helper(root->left);
        
        vector <int> right = helper(root->right);
        
        int isBst = 1;
        
        if(root->val <= left[1] || root->val >= right[2])
            isBst = 0;
        
        int sum = root->val + left[0] + right[0];
        
        if(isBst && left[3] && right[3] && sum > ans)
        {
            ans = sum;
        }
        
        return {sum, max(root->val, max(left[1],right[1])) , min(root->val, min(left[2], right[2])), isBst};
        
    }
    
    
    int maxSumBST(TreeNode* root) {
            
        ans = 0;
        
        helper(root);
        
        return ans;
    }
};