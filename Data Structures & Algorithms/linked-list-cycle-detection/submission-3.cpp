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

class Solution 
{
public:
    bool hasCycle(ListNode* head) 
    {
        ListNode* single = head;
        ListNode* duble = head;
        while(single != nullptr && duble != nullptr)
        {
            single = single->next;
            if(duble->next == nullptr) return false;
            duble = duble->next->next; 
            if(single == duble) return true;
        }
        return false;
    }
};
