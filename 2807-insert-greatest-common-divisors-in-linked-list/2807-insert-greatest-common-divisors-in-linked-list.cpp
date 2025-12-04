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
         while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
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