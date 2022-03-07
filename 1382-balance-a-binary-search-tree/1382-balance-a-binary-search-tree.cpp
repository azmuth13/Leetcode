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
    
    void inorder(TreeNode* root, vector <int> &vec)
    {
        if(!root) return;
        inorder(root->left, vec);
        vec.push_back(root->val);
        inorder(root->right, vec);
    }
    
    TreeNode* builder(vector <int> &vals, int l, int r)
    {
        if(l > r)
            return NULL;
        
        int mid = (l+r)/2;
        
        TreeNode* root = new TreeNode(vals[mid]);
        
        root->left = builder(vals, l, mid-1);
        root->right = builder(vals, mid + 1, r);
        return root;
    }
    
    TreeNode* balanceBST(TreeNode* root) {
        
        vector <int> vals;
        inorder(root,vals);
        
        int n = vals.size();
            
        TreeNode* ans = builder(vals, 0, n-1);
        
        return ans;
    }
};