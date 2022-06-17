/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    ListNode* store;
    map < pair <ListNode*, TreeNode* >, bool > mp;
    bool helper(ListNode* head, TreeNode* root)
    {
        if(head == NULL)
            return true;
        
        if(!root)
            return false;
        
        if(mp.find({head,root}) != mp.end())
             return mp[{head,root}];
        
        bool ans = false;
        
        if(root->val == head->val)
        {
            ans |= helper(head->next, root->left);
            if(ans) return true;
            ans |= helper(head->next, root->right);
            if(ans) return true;
        }
        
        ans |= helper(store, root->left);
        if(ans) return true;
        ans |= helper(store, root->right);
        if(ans) return true;
        //return ans;
        return mp[{head,root}] = ans;
    }
    
    bool isSubPath(ListNode* head, TreeNode* root) {
        store = head;
        return helper(head,root);
    }
};