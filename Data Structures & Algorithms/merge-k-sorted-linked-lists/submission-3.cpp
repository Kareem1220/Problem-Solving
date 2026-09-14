/**
 * Definition for singly-linked list.
 * struct ListNode 
 {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution // REDO : Optimal Solution Using MinHeap
{
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        for(int i = 0 ; i < lists.size() ; i++)
        {
            if(lists[i] == nullptr) 
            {
                lists.erase(lists.begin() + i);
                i--;
            }
        }
        if(lists.empty()) return nullptr;
        ListNode* h = lists[0];
        for(int i = 1 ; i < lists.size() ; i++)
        {
            while(h->next != nullptr) 
            {
                h = h->next;
            }
            h->next = lists[i];
        }
        ListNode* t = lists[0];
        return sortList(t);
    }
    ListNode* sortList(ListNode* t)
    {
        if(!t || !t->next) return t;
        ListNode* slow = t;
        ListNode* fast = t->next;
        while(fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* rightList = slow->next;
        slow->next = nullptr;

        ListNode* left = sortList(t);
        ListNode* right = sortList(rightList);

        return merge(left,right);
    }
    ListNode* merge(ListNode* l1 , ListNode* l2)
    {
        ListNode dummy(0);
        ListNode* tail = &dummy;
        while(l1 != nullptr && l2 != nullptr)
        {
            if(l1->val <= l2->val)
            {
                tail->next = l1;
                l1 = l1->next;
            }
            else
            {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        tail->next = l1 ? l1 : l2;
        return dummy.next;
    }
};
