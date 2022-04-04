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
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        
        ListNode* copy = head;
        
        int sz = 0;
        
        while(copy != NULL)
        {
            sz++;
            copy = copy->next;
        }
       
        int ptr = sz - k + 1;
        
        int cnt = 0;
        
        // k + x + k = sz;
        // 2k + x = sz;
        if(k > sz/2)
         k = sz - k + 1;
        int x = sz - 2*k + 1;
        
        ListNode* copy1 = head;
        
        ListNode* copy2 = head;
        
        while(x--)
            copy2 = copy2->next;
        
        while(k-- > 1)
        {
            copy1 = copy1->next;
            copy2 = copy2->next;
        }
        
        swap(copy1->val, copy2->val);
        
        return head;
        
    }
};