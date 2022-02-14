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
    map <int, int> mp;
    
    void getLevel(TreeNode* root, int l)
    {
        if(!root)
            return;
            
        mp[root->val] = l;
        
        getLevel(root->left, l+1);
        getLevel(root->right, l+1);
        
    }
    
    int getParent(TreeNode* root, int v)
    {
        
        if(!root->left && !root->right)
            return -1;
        
        int p1 = -1, p2 = -1;
        
        if(root->left)
        {
            if(root->left->val == v)
                return root->val;
            else
                p1 = getParent(root->left, v);
        }
        
        if(root->right)
        {
            if(root->right->val == v)
                return root->val;
            else
                p2 = getParent(root->right,v);
        }
            
        if(p1==-1)
            return p2;
        
        return p1;
    
    }
    
    bool isCousins(TreeNode* root, int x, int y) {
        // if parents are not same and they are on the same level, they are cousins
        
    
        int px = getParent(root,x);
        int py = getParent(root, y);
            
        // cout << px << " " << py << endl;
        
        getLevel(root, 0);
        
        if(px == py)
            return false;
        
        if(mp[x] != mp[y])
            return false; 
        
        return true;
        
    }
};