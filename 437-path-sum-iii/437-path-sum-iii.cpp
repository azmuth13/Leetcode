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
    
    unordered_map <int, int> mp;
    int ans = 0;
    int nodes = 0;
    void helper(TreeNode* root, int sum, int target)
    {
        if(!root)
            return;
        nodes++;
        sum += root->val;
        
        mp[sum]++;
        
        ans += mp[sum - target];
        
        helper(root->left, sum, target);
        helper(root->right, sum, target);
        
        mp[sum]--;
        
    }
    
    int pathSum(TreeNode* root, int targetSum) {
        mp[0]=1;
        helper(root, 0, targetSum);
        return (targetSum == 0 ? ans - nodes : ans);
    }
};