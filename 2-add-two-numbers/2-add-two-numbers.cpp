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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int len1=0,len2=0,carry=0;
        ListNode * t1=l1;
        ListNode * t2=l2;
        ListNode * ans=new ListNode();
        ListNode * k=ans;
        while(t1){
            len1++;
            t1=t1->next;
        }
         while(t2){
            len2++;
            t2=t2->next;
        }
        t1=l1;
        t2=l2;
        if(len1==len2){
            while(t1){
                int x;
                x=t1->val+t2->val+carry;  
               
                
                if(x>9){
                    carry=1;
                    x=x%10;
                }else{
                    carry=0;
                }
                k->next=new ListNode(x);
                k=k->next;
                t1=t1->next;
                t2=t2->next;
            }
            if(carry==1){
                k->next= new ListNode(carry);
                k=k->next;
            }
        }
        if(len1>len2){
            while(t2){
                int x;
                 x=t1->val+t2->val+carry;  
                if(x>9){
                    carry=1;
                    x=x%10;
                }else{
                    carry=0;
                }
                k->next=new ListNode(x);
                k=k->next;
                t1=t1->next;
                t2=t2->next;
            }
            while(t1){
                int x;
                x=t1->val+carry;  
                if(x>9){
                    carry=1;
                    x=x%10;
                }else{
                    carry=0;
                }
                k->next=new ListNode(x);
                k=k->next;
                t1=t1->next;
            }
             if(carry==1){
                k->next = new ListNode(1);
                 k=k->next;
            }
        }
        carry=0;
        if(len1<len2){
            while(t1){
                int x;
                 x=t1->val+t2->val+carry;  
               if(x>9){
                    carry=1;
                    x=x%10;
                }else{
                    carry=0;
                }
                k->next=new ListNode(x);
                k=k->next;
                t1=t1->next;
                t2=t2->next;
            }
            while(t2){
                int x;
                x=t2->val+carry;  
               if(x>9){
                    carry=1;
                    x=x%10;
                }else{
                    carry=0;
                }
                
                k->next=new ListNode(x);
                k=k->next;
                t2=t2->next;
            }
             if(carry==1){
                k->next= new ListNode(carry);
                 k=k->next;
            }
        }
        
        return ans->next;
    }
};