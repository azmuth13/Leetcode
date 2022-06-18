/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *res;
    
    bool helper(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if(root == NULL)
            return false;
        
        bool ans1 = false;
        
        if(root->val == p->val || root->val == q->val)
            ans1 = true;
        
        bool ans2 = helper(root->left, p, q);
        bool ans3 = helper(root->right, p, q);
        
        if((ans1&&ans2) || (ans1&&ans3) || (ans2&&ans3))
        {
            res = root;
            return true;
        }
        
        return (ans1 | ans2 | ans3);
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
//         helper(root, p, q);
        
//         return res;
        
        if(!root)
            return NULL;
        
        if(root->val == p->val || root->val == q->val)
            return root;
        
        TreeNode* lc1 = lowestCommonAncestor(root->left,p,q);
        TreeNode* lc2 = lowestCommonAncestor(root->right,p,q);

        
        if(lc1 && lc2)
            return root;
        else if(lc1)
            return lc1;
        else 
            return lc2;
    }
};