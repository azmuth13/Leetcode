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
    
    pair <int, int> helper(TreeNode* root, int &ans)
    {
        if(!root)
            return {0,0};
        
        pair <int, int> a = helper(root->left, ans);
        pair <int, int> b = helper(root->right, ans);
        
        int sum = root->val + a.first + b.first;
        int cnt = 1 + a.second + b.second;
        
        ans += (root->val == sum/cnt);
        
        return {sum, cnt};
    }
    
    int averageOfSubtree(TreeNode* root) {
        
        int ans = 0;
        
        helper(root, ans);
        return ans;
    }
};