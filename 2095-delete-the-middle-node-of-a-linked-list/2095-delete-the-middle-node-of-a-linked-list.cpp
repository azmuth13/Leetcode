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

int print(ListNode* head)
{
    ListNode* itr = head;
    int cnt = 0;
        
    while(itr != NULL)
    {
        cnt++;
        //cout << itr->val << " ";
        itr = itr->next;
    }
    
    //cout << endl;
    
    return cnt;
}

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        
        if(!head)
        {
            return head;
        }
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* prev = NULL;
 
        int flag = 0;
        
        int size = print(head);
        if(size == 1)
        {
            return NULL;
        }
        if(size%2 == 0)
        while(!flag)
        {
            if(fast->next->next != NULL)
                fast = fast->next->next;
            else
            {
                flag = 1;
                fast = fast->next;
            }
            
            prev = slow;
            slow = slow->next;
        }
        else
        while(!flag)
        {
            if(fast->next->next->next != NULL)
                fast = fast->next->next;
            else
            {
                flag = 1;
                fast = fast->next;
            }
            
            prev = slow;
            slow = slow->next;
        }
        prev->next = slow->next;
        
        
        return head;
        
    }
};