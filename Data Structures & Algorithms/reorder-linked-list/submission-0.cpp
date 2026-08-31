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
    void reorderList(ListNode* head) 
    {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next; 
        }
        ListNode* current = slow->next;
        slow->next = nullptr;
        ListNode* previous = nullptr; 
        ListNode* next; 
        while(current != nullptr)
        {
            next = current->next; 
            current->next = previous;
            previous = current;
            current = next;
        }
        ListNode* right = previous;
        ListNode* left = head;
        ListNode* nextleft;
        ListNode* nextright;
        int round = 2;
        while(right != nullptr && left != nullptr)
        {
            if(round % 2 == 0)
            {
                nextleft = left->next;
                left->next = right;
                left = nextleft;
                round++;
            }
            else 
            {
                nextright = right->next;
                right->next = left;
                right = nextright;
                round++;
            }
        }
    }
};
