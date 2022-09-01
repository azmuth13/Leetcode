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
    
    int helper(TreeNode* root, int maxi)
    {
        if(!root)
            return 0;
        
        int a = helper(root->left, max(maxi, root->val));
        int b = helper(root->right, max(maxi, root->val));
        int c = 0;;
        if(root->val >= maxi)
            c++;
        return a + b + c;
    }
    
    int goodNodes(TreeNode* root) {
        int ans = 0;
        int maxi = -1e5;
        ans = helper(root,maxi);
        return ans;
    }
};