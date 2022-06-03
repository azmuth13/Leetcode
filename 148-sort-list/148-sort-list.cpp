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
    ListNode* sortList(ListNode* head) {
        
        // merge sort on linked lists  
        // divide in two parts
        // sort them individually
        // merge them
        
        if(head == NULL || head->next == NULL)
            return head;
        
        ListNode *mid = getMid(head);
        ListNode *left = sortList(head);
        ListNode *right = sortList(mid);
        return merge(left, right);    
    }
    
    ListNode * getMid(ListNode *head)
    {
//         ListNode* midPrev = nullptr;
//         while (head && head->next)
//         {
//             midPrev = (midPrev == nullptr) ? head : midPrev->next;
//             head = head->next->next;
//         }
        
//         ListNode* mid = midPrev->next;
//         midPrev->next = nullptr;
        
        ListNode *fast = head, *slow = head;
        ListNode *prev = nullptr;
        
        while(fast && fast->next)
        {   
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
       
        prev->next = nullptr;
        return slow;
    }
    
    ListNode* merge(ListNode *L1, ListNode *L2)
    {
        if(L1 == NULL && L2 == NULL)
            return NULL;
        else if(L1 == NULL)
            return L2;
        else if(L2 == NULL)
            return L1;
        
        ListNode *L3 = L1;
        
        if(L1->val > L2->val)
        {
            L3 = L2;
            L2 = L2->next;
        }
        else
        {
            L1 = L1->next;
        }
        
        ListNode *temp = L3;
        
        while(L1 && L2)
        {
            if(L1->val < L2->val)
            {
                L3->next = L1;
                L3 = L3->next;
                L1 = L1->next;
            }
            else
            {
                L3->next = L2;
                L3 = L3->next;
                L2 = L2->next;
            }
        }
        
        if(L1)
            L3->next = L1;
        else
            L3->next = L2;
        
        return temp;
    }
};