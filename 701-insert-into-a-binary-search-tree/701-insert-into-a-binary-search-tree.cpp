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
    
    void helper(TreeNode* root, int val)
    {
        
        if(root->val > val)
        {
            if(root->left)
                helper(root->left,val);
            else
            {
                TreeNode* leaf = new TreeNode(val);
                root->left = leaf;
                return;
            }
        }
        else if(root->val < val)
        {
            if(root->right)
                helper(root->right, val);
            else
            {
                TreeNode* leaf = new TreeNode(val);
                root->right = leaf;
                return;
            }
        }
    }
    
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        
        if(!root)
            return new TreeNode(val);
        
        if(root->val < val)
        {
            root->right = insertIntoBST(root->right,val);
        }
        else
        {
            root->left = insertIntoBST(root->left,val);
        }
        
        return root;
    }
};