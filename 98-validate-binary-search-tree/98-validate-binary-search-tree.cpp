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
    
//     bool helper(TreeNode *root, TreeNode * &prev)
//     {
//         if(root == NULL)
//             return true;
        
//         bool ans1 = helper(root->left, prev);
//         if(!ans1)
//             return false;
        
//         if(prev!=NULL && root->val <= prev->val)
//             return false;
        
//         prev = root;
        
//         bool ans2 = helper(root->right, prev);
//         return ans2;
        
//     }
    
    bool res;
    
    vector <long long> helper(TreeNode* root)
    {
        if(!root)
        return {LONG_LONG_MIN,LONG_LONG_MAX};

        vector <long long> l = helper(root->left);
        vector <long long> r = helper(root->right);

        if(root->val <= l[0] || root->val >= r[1])
        {
            res = 0;
            return {-1,-1};
        }

        return {max((long long)root->val, max((long long)r[0],(long long)l[0])), min((long long)root->val, 
        min((long long)l[1],(long long)r[1]))};

    }
    
    bool isValidBST(TreeNode* root) {
        
        res = 1;

        helper(root);
        
        return res;
    }
};