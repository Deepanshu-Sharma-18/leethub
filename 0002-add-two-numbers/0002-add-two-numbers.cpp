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
        ListNode* res = new ListNode(1);
        ListNode* t = res;
        int carry = 0;

        while(l1 && l2){
            int sum = l1->val + l2->val + carry;
            carry = 0;
            if(sum > 9){
                carry = 1;
                sum = sum % 10;
            }

            ListNode* nw = new ListNode(sum);
            res->next = nw;
            res = res->next;
            
            l1 = l1->next;
            l2 = l2->next;
        }

        while(l1){
            int sum = l1->val + carry;
            carry = 0;
            if(sum > 9){
                carry = 1;
                sum = sum % 10;
            }
            l1 = l1->next;
            ListNode* nw = new ListNode(sum);
            res->next = nw;
            res = res->next;
        }

        while(l2){
            int sum = l2->val + carry;
            carry = 0;
            if(sum > 9){
                carry = 1;
                sum = sum % 10;
            }
            l2 = l2->next;
            ListNode* nw = new ListNode(sum);
            res->next = nw;
            res = res->next;
        }

        if(carry){
            ListNode* nw = new ListNode(1);
            res->next = nw;
            res = res->next;
        }

        return t->next;
    }
};