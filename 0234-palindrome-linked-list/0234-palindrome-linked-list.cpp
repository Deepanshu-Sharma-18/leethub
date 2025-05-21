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
        ListNode *fast = head;
        ListNode* slow = head;

        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }

        
        ListNode* temp = head;
        ListNode* curr = head;
        ListNode* prev = NULL;

        while(temp != slow){
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        if(fast != NULL && fast->next == NULL) slow = slow->next;

        while(prev && slow){
            if(prev->val != slow->val) return false;
            prev = prev->next;
            slow = slow->next;
        }

        return true;
    }
};