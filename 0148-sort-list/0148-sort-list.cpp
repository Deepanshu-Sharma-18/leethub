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
    ListNode* merge(ListNode* a, ListNode* b){
        ListNode* nw = new ListNode(0);
        ListNode* t = nw;

        while(a && b){
            if(a->val <= b->val){
                nw->next = a;
                a = a->next;
            }else{
                nw->next = b;
                b = b->next;
            }

            nw = nw->next;
        }

        while(a){
            nw->next = a;
            a = a->next;
            nw = nw->next;
        }

        while(b){
            nw->next = b;
            b = b->next;
            nw = nw->next;
        }

        return t->next;
    }

    ListNode* mergeSort(ListNode* temp){
        if(!temp->next) return temp;

        ListNode* slow = temp, *fast = temp;

        ListNode* prev;
        while(fast && fast->next){
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }

        prev->next = nullptr;

        ListNode* a = mergeSort(temp);
        ListNode* b = mergeSort(slow);
        return merge(a,b);
    }

    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        
        return mergeSort(head);
    }
};