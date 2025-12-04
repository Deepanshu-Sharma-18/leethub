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
    int gca(int a, int b){
        for(int i=min(a,b); i>0; i--){
            if(a % i == 0 && b % i == 0) return i;
        }
        return 1;
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode *prev , *curr;
        prev = head;
        curr = head->next;

        while(curr){
            int t = gca(prev->val, curr->val);
             ListNode* temp = new ListNode(t);
             prev->next = temp;
             temp->next = curr;
            
            prev = curr;
            curr = curr->next;
        }

        return head;

    }
};