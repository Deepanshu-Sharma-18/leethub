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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* prev = head, *curr = head;
        ListNode* pp = nullptr;
        int i = 0;
        while(curr){
            i++;
            if(i == k){
                ListNode* nxt = curr->next;
                ListNode* p = nxt;
                ListNode* start = prev;
                while(prev != nxt){
                    ListNode* t = prev->next;
                    prev->next = p;
                    p = prev;
                    prev = t;
                }
                if(!pp){
                    head = p;
                }else{
                    pp->next = p;
                }
                pp = start;

                prev = nxt;
                i = 0;
                curr = nxt;
                continue;
            }

            curr = curr->next;
        
        }   

        return head;
    }
};