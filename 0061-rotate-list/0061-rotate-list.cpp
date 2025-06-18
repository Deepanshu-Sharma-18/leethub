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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || k == 0) return head;
        ListNode* temp = head;
        int size = 0;
        while(temp){
            size++;
            temp = temp->next;
        }

        k = k % size;
        if(k == 0) return head;

        size = size - k + 1;
        temp = head;
        ListNode* prev;
        while(temp && --size > 0){
            prev = temp;
            temp = temp->next;
        }

        prev->next = nullptr;
        ListNode* start = temp;
        while(temp->next){
            temp = temp->next;
        }
        temp->next = head;
        head = start;

        return head;
    }
};