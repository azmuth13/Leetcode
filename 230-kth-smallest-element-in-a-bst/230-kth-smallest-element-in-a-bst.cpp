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
 **/
class Solution {
public:

    
    int inorder(TreeNode* root, int &k)
    {
        if(root == NULL)
            return 1e9 + 7;
        int a1 = 1e9, a2 = 1e9;
        
        if(root->left)
            a1 = inorder(root->left, k);
        
        //cout<<root->val<<endl;
        k--;
        int ans = 1e9;
        
        if(k == 0 )
        {
           ans = root->val;
        }
        
        
        if(root->right)
            a2 = inorder(root->right, k);
        
        return min(ans, min(a1, a2));
    }
   
    
    int kthSmallest(TreeNode* root, int k) {
        
        int ans = 0;
        
        return inorder(root, k);
        
    }
};