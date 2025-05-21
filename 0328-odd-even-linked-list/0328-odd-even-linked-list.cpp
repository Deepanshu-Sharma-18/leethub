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
        if(!head || !head->next) return head;
        ListNode* odd = head;
        ListNode* even = head->next;

        ListNode* start_odd = odd;
        ListNode* start_even = even;

        ListNode* temp = head->next->next;
        int i = 3;
        while(temp != NULL){
            if(i % 2 == 0){
                even->next = temp;
                even = even->next;
            }else{
                odd->next = temp;
                odd = odd->next;
            }

            i++;
            temp = temp->next;
        }

        odd->next = start_even;
        even->next = NULL;

        return start_odd;
    }
};