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
    
    void inorder(TreeNode* root, vector <TreeNode*> &vec)
    {
        if(!root) return;
        inorder(root->left, vec);
        vec.push_back(root);
        inorder(root->right, vec);
    }
    
    TreeNode* builder(vector <TreeNode*> &vals, int l, int r)
    {
        if(l > r)
            return NULL;
        
        int mid = (l+r)/2;
        
        vals[mid]->left = builder(vals, l, mid-1);
        vals[mid]->right = builder(vals, mid + 1, r);
        
        return vals[mid];
    }
    
    TreeNode* balanceBST(TreeNode* root) {
        
        vector <TreeNode*> vals;
        inorder(root,vals);
        
        int n = vals.size();
            
        TreeNode* ans = builder(vals, 0, n-1);
        
        return ans;
    }
};