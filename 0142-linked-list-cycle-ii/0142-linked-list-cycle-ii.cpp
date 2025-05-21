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
        ListNode* fast = head;
        ListNode* slow = head;

        bool f = false;

        while(fast != NULL && fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;

            if(slow == fast){
                f = true;
                break;
            }
        }
        if(!f) return NULL;
        slow = head;

        while(slow != fast){
            slow = slow->next;
            fast = fast->next;
            if(slow == fast){
                break;
            }
        }

        return slow;
    }
};