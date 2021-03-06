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
    set <int> st;
    void helper(TreeNode* root)
    {
        if(!root)
            return;
        
        st.insert(root->val);
        
        helper(root->left);
        helper(root->right);
    }
    
    int findSecondMinimumValue(TreeNode* root) {
        
        helper(root);
        st.erase(st.begin());
        if(st.size() == 0)
            return -1;
        return *st.begin();
    }
};