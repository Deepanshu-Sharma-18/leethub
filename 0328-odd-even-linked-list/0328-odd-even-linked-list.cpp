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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* odd = new ListNode(1);
        ListNode* even = new ListNode(1);

        ListNode* s_even = even;
        ListNode* s_odd = odd;

        int k = 1;
        ListNode* temp = head;
        while(temp){
            ListNode* t = temp->next;
            if(k % 2 == 0){
                even->next = temp;
                even = even->next;
            }else{
                odd->next = temp;
                odd = odd->next;
            }
            k++;

            temp = t;
        }
        even->next = nullptr;
        odd->next = s_even->next;

        return s_odd->next;

    }
};