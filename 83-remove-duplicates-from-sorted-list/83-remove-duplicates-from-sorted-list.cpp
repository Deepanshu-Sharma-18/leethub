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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode * temp=head;
        if(temp==NULL){
       return head;
    }
    ListNode* temp2=head->next;
    while(temp2){
        if(temp->val==temp2->val){
            temp->next=temp2->next;
            temp2=temp2->next;
        }
        else{
            temp=temp->next;
            temp2=temp2->next;
        }
    }
    return head;

    }
};