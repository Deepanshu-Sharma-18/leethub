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
    int pairSum(ListNode* head) {
        int count = 1;

        ListNode* temp = head;

        while(temp != NULL){
            count++;
            temp = temp->next;
        }

        int mid = count /2;
        count = 0;
        temp = head;
        while(count < mid){
            temp = temp->next;
            count++;
        }
        
        ListNode *prev = NULL;

        while(temp != NULL){
            ListNode* nxt = temp->next;
            temp->next = prev;
            prev = temp;
            temp = nxt;
        }
        temp = head;
        int m = INT_MIN;
        while(prev != NULL){
            m = max(m , prev->val + temp->val);
            temp = temp->next;
            prev = prev->next;
        }

        return m;
    }
};