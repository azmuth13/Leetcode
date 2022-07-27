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
    using LLNode = ListNode;
    void print(LLNode* node)
    {
        while(node)
        {
            cout << node->val << ' ';
            node = node->next;
            // if(node->val == node->next->val)
            // break;
        }
        cout << endl;
    }
    LLNode* reverse(LLNode* first, LLNode* last)
    {
        LLNode* p, *q, *r = NULL;
        q = NULL;
        p = first;
        last= last->next;
        while(p!=NULL)
        {
            r = q;
            q = p;
            p = p->next;
            q->next = r;
            if(p == last)
            break;
        }
       // print(q);
        return q;
    }
    int getLen(LLNode* rem)
    {
        int cnt = 0;
        while(rem)
        {
            cnt++;
            rem = rem->next;
        }
        return cnt;
    }
    ListNode* reverseBetween(ListNode* node, int i, int j) {
        i--,j--;
        int len = getLen(node);
        int a = i, b = j;
        LLNode* first, *last;
        LLNode* temp = first, *temp2 = first;
        first = node;
        last = node;
        LLNode* head = node;

        while(i--)
        {
            //cout << "YES1\n";
            temp = first;
            first = first->next;
        }

        while(j--)
        {
            //cout << "YES2\n";
            last = last->next;
        }

        //cout << first->val << endl;
        //cout << last->val <<endl;
        temp2 = last->next;
        LLNode* pri = reverse(first, last);
        //print(pri);
        temp->next = pri;
        if(len == b-a+1)
        {
            return pri;
        }


        //cout << temp->next->val << endl;

        if(a == 0)
        {
            temp = pri;
            //print(temp);
            LLNode* res = pri;
            while(temp && temp->next)
            {
                //cout << temp->val << endl;
                temp = temp->next;
            }
            temp->next = temp2;
            return res;
        }
        while(temp && temp->next)
        {
            //cout << temp->val << endl;
            temp = temp->next;
        }

        temp->next = temp2;
        return head;
        
    }
};