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
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next) return true;
        ListNode* fast = head, *slow = head;
        ListNode* prev;

        while(fast && fast->next){
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }

        if(fast){
            prev->next = nullptr;
            slow = slow->next;
        }

        prev = nullptr;
        while(slow){
            fast = slow->next;
            slow->next = prev;
            prev = slow;
            slow = fast;
        }
        fast = head;
        while(prev && fast){
            if(prev->val != fast->val) return false;
            prev = prev->next;
            fast = fast->next;
        }

        return true;
    }
};