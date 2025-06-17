/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head, *slow = head;
        bool f = false;
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow){
                f = true;
                break;
            }
        }

        if(!f) return nullptr;

        fast = head;
        while(fast != slow){
            fast = fast->next;
            slow = slow->next;
        }

        return slow;
    }
};