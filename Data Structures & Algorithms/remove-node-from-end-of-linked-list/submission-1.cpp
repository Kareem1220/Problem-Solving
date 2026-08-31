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
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        ListNode* t = head;
        int i = 1;
        while(t->next != nullptr)
        {
            t = t->next;
            i++;
        }
        if(i == 1) return nullptr;
        if(i == n) 
        {
            head = head->next;
            return head;
        }
        ListNode* p = head;
        ListNode* pnext;
        ListNode* pprev;
        while(i > n)
        {
            pprev = p;
            p = p->next;
            pnext = p->next;
            i--;
        }
        pprev->next = pnext;
        return head; 
    }
};
