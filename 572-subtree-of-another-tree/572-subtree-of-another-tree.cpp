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
    
    bool check(TreeNode* a, TreeNode* b)
    {
        if(!a && !b)
            return true;
        
        if(!a)
            return false;
        
        if(!b)
            return false;
        
        if(a->val != b->val)
            return false;
        
        return check(a->left, b->left) && check(a->right, b->right);
        
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root && !subRoot)
            return true;
        
        if(!root)
            return false;
        
        if(!subRoot)
            return false;
        
        bool ans = false;
        
        if(check(root, subRoot))
            ans = true;
        
        return ans || isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
        
    }
};