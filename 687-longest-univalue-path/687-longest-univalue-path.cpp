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
    
//     int getHeight(TreeNode* root, int val)
//     {
//         if(!root || root->val != val)
//             return 0;
        
//         return 1 + max(getHeight(root->left, val), getHeight(root->right, val));
//     }
    
    int HH = 0;
        
    map <TreeNode* , int> mp;
    
    
    int helper(TreeNode* root, int val)
    {
        if(!root)
            return 0;
        
        if(root->val == val)
        {
            int l = helper(root->left, val);
            int r = helper(root->right, val);
            HH = max(HH, l+r+1);
            return 1 + max(l,r);
        }
        else
        {
            int l = helper(root->left, root->val);
            int r = helper(root->right, root->val);
            
            HH = max(HH, l+r+1);
            
            return 0;
        }
    }
    
    int longestUnivaluePath(TreeNode* root) {
        
        if(!root)
            return 0;
        
        helper(root, root->val);
        
        return HH-1;
        
    }
};