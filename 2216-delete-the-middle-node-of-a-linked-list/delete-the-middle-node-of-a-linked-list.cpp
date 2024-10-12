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
    ListNode* deleteMiddle(ListNode* head) {

        
        ListNode * temp = head;
        int count=0;

        while(temp != NULL){
            count++;
            temp = temp->next;
        }

        if(count == 1)return NULL;

        int mid = count/2;

        count = 0;

        temp = head;

       
            while(count < mid - 1){
                temp = temp->next;
                count++;
            }
            
            if(temp->next != NULL) temp->next = temp->next->next;
            else temp->next = NULL;


        return head;
    }
};