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
    map <int, int> mp;
    
    int helper(TreeNode* root)
    {
        if(!root)
            return -1e9;
        
        int sum = 0;
        
        int sumLeft = helper(root->left);
        int sumRight = helper(root->right);
        
        if(sumLeft != -1e9)
        ans = max(ans, ++mp[sumLeft]);
        
        if(sumRight != -1e9)
        ans = max(ans, ++mp[sumRight]);
        
        return root->val + ((sumLeft == -1e9)?0:sumLeft) + ((sumRight == -1e9)?0:sumRight);
    }
    
    vector<int> findFrequentTreeSum(TreeNode* root) {
        ans = 0;
        
        int res = helper(root);
        ans = max(ans, ++mp[res]);
        
        vector <int> result;
        
        for(auto &x : mp)
        {
            if(x.second == ans)
                result.push_back(x.first);
            //cout << x.first << " " << x.second << endl;
        }
        
        return result;
    }
};