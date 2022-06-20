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
    
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return NULL;
        if(root->val > key)
        {
            root->left = deleteNode(root->left,key);
        }
        else if(root->val < key)
        {
            root->right = deleteNode(root->right,key);
        }
        else
        {
            // found
            
            if(!root->left && !root->right)
            {
                return NULL;
            }
            else if(root->left && root->right)
            {
                // largest in the left subtree
                    
                TreeNode* del = root->left;
                while(del->right)
                {
                    del = del->right;
                }
                root->val = del->val;
                root->left = deleteNode(root->left,del->val);
            }
            else if(root->left)
            {
                return root->left;
            }
            else if(root->right)
            {
                return root->right;
            }
        }
        return root;
    }
};