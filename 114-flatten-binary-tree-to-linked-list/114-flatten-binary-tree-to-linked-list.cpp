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
    
    void print(TreeNode* root)
    {
        // leftST , Root, RightST
        
        TreeNode* curr = root;
         
        while(curr != NULL)
        {
            if(curr->left)
            {
                TreeNode* pred = curr->left;
                
                while(pred->right && pred->right != curr)
                    pred = pred->right;
                
                if(pred->right == NULL)
                {
                    pred->right = curr;
                    curr = curr->left;
                }
                else
                {
                    pred->right = NULL;
                    cout << curr->val << " ";
                    curr = curr->right;
                }    
            }
            else
            {
                cout << curr->val << " ";
                curr = curr->right;
            }
        }
    }
    
    void flatten(TreeNode* root) {
        
        TreeNode* curr = root;
        
        while(curr != NULL)
        {
            if(curr->left)
            {
                TreeNode* pred = curr->left;
                
                while(pred->right && pred->right != curr)
                    pred = pred->right;
                
                if(pred->right == NULL)
                {
                    pred->right = curr;
                    curr = curr->left;
                }
                else
                {
                    // pred->right = NULL;
                    // cout << curr->val << " ";
                    // curr = curr->right;
                    
                    TreeNode* temp = curr->right;
                    curr->right = curr->left;
                    curr->left = NULL;
                    pred->right = temp;
                    curr = temp;
                    
//                     tn* tmp=cur->right;
//                     cur->right=cur->left;
//                     cur->left = nullptr;
//                     rMost->right=tmp;
//                     cur = tmp;
                }
            }
            else
            {
                //cout << curr->val << " ";
                curr = curr->right;
            }
        }
    }
};