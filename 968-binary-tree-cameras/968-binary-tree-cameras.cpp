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
    
    /*
            return val = 0 means no camera at this node and 
            it is not monitored by any of the child
            
            return val = 1 means no camera at this node but 
            it is monitored by either or both of its children
            
            retrun val = 2 means we have camera at this node    
    */
    
    int helper(TreeNode* root, int &sum)
    {
        if(!root)
            return 1;
        
        int left = helper(root->left,sum);
        
        int right = helper(root->right,sum);

        if(left == 0 || right == 0)
        {
            sum++;
            return 2;
        }
        else if(left == 2 || right == 2)
        {
            return 1;
        }
        else
        {
            return 0;
        }
        
        return 1e9;
    }
    
    
    int minCameraCover(TreeNode* root) {
        
        if(!root)
        {
            return 0;
        }
        int sum = 0;
        int val = helper(root,sum);
        if(!val)
            sum++;
        return sum;
    }
        
};