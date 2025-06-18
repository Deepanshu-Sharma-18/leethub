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
        if(!head || !head->next) return nullptr;
        int size = 0;
        ListNode* temp = head;
        while(temp){
            temp = temp->next;
            size++;
        }

        size = size - n + 1;

        if(size == 1){
            head = head->next;
            return head;
        } 

        temp = head;
        ListNode* prev;
        while(temp && size > 1){
            prev = temp;
            temp = temp->next;
            size--;
        }

        prev->next = temp->next;

        return head;
    }
};