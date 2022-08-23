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
    
    int getSize(ListNode* temp)
    {
        ListNode* slow = temp;
        ListNode* fast = temp;
        int cnt = 0;
        int flag = 0;
        
        while(1)
        {
            if(fast==NULL)
            {
                break;
            }
            
            if(fast->next == NULL)
            {
                flag = 1;
                break;
            }
            
            cnt++;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return cnt*2 + flag;
    }
    
    bool isPalindrome(ListNode* head) {
        ListNode* temp = head;
        int sz = getSize(temp);

        ListNode* q = NULL;
        ListNode* r = NULL;
        ListNode* s = head;
        
        int half = sz/2;
        
        while(half--)
        {
            q = r;
            r = s;
            s = s->next;
            r->next = q;
        }
        
        if(sz&1)
            s = s->next;
        
        while(r != NULL && s != NULL)
        {
            if(r->val != s->val)
                return false;
            
            r = r->next;
            s = s->next;
        }
        
        return true;
    }
};