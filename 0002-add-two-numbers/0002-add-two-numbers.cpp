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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;

        ListNode* ans = new ListNode(0);

        ListNode* temp = ans;

        while(l1 && l2){
            int sum = l1->val + l2->val + carry;
            carry = 0;
            if(sum > 9){
                sum %= 10;
                carry = 1;
            }
            ans->next = new ListNode(sum);
            ans = ans->next;
            l1 = l1->next;
            l2 = l2->next;
        }

        while(l1){
            int sum = l1->val + carry;
            carry = 0;
            if(sum > 9){
                sum %= 10;
                carry = 1;
            }
            ans->next = new ListNode(sum);
            ans = ans->next;
            l1 = l1->next;
        }

        while(l2){
            int sum = l2->val + carry;
            carry = 0;
            if(sum > 9){
                sum %= 10;
                carry = 1;
            }
            ans->next = new ListNode(sum);
            ans = ans->next;
            l2 = l2->next;
        }

        if(carry == 1) ans->next = new ListNode(carry);

        return temp->next;
    }
};