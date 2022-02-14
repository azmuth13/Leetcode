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

    int helper(TreeNode* root, int val)
    {
        if(!root || root->val != val)
            return 0;
        
        int l = helper(root->left, val);
        int r = helper(root->right, val);
        
        HH = max(HH, l+r);
        
        return max(l, r) + 1;
    }
    
    int longestUnivaluePath(TreeNode* root) {
        
        if(!root)
            return 0;
        
        HH = 0;
        
        helper(root, root->val);
        int ans = HH;
        int ansL = longestUnivaluePath(root->left);
        int ansR = longestUnivaluePath(root->right);
        
        return max(ans, max(ansL, ansR));
        
    }
};