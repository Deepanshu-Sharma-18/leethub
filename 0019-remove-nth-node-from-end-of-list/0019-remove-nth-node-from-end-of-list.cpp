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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        int count = 0;

        while(temp != NULL){
            temp = temp->next;
            count++;
        }

        temp = head;
        ListNode* prev = head;
        for(int i=1;i<count-n+1;i++){
            prev = temp;
            temp = temp->next;
        }

        if(prev == temp) return head->next ;
        else prev->next = temp ? temp->next : nullptr;

        return head;
    }
};