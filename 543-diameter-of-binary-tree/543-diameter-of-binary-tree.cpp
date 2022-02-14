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
    int ans = 0;
    int getHeight(TreeNode* root)
    {
        if(!root)
            return 0;
        
        int l = getHeight(root->left);
        int r = getHeight(root->right);
        
        ans = max(l + r, ans);
        return max(l,r) + 1;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        
        getHeight(root);
        return ans;
    }
};