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

    ListNode* merge(ListNode* a , ListNode* b){
        ListNode* ans = new ListNode(0);
        ListNode* temp = ans;

        while(a && b){
            if(a->val < b->val){
                ans->next = a;
                ans = ans->next;
                a = a->next;
            }else{
                ans->next = b;
                ans = ans->next;
                b = b->next;
            }
        }

        while(a){
            ans->next = a;
            ans = ans->next;
            a = a->next;
        }

        while(b){
            ans->next = b;
            ans = ans->next;
            b = b->next;
        }

        return temp->next;
    }

    ListNode* mergeSort(ListNode* head ){
        if(head->next == nullptr) return head;

        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* prev = head;

        while(fast && fast->next){
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }
        prev->next = NULL;

        ListNode* a = mergeSort(head);
        ListNode* b = mergeSort(slow);
        return merge(a,b);
    }

    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;

        return mergeSort(head);
    }
};