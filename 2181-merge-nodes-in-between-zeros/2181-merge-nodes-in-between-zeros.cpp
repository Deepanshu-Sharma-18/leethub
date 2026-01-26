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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* temp = head;
        ListNode* start = head;
        ListNode* itr = start;

        temp = temp->next;
        int sum = 0;
        while(temp){
            if(temp->val == 0){
                ListNode* t = new ListNode(sum);
                itr->next = t;
                t->next = nullptr;
                itr = t;
                sum = 0;    
            }else{
                sum += temp->val;
            }
            temp = temp->next;
        }

        return start->next;
    }
};