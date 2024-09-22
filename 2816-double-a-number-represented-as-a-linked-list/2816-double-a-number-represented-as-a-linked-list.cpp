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
    ListNode*rever(ListNode*head){
        if(!head)return nullptr;

        ListNode*cur=head;
        ListNode*prev=NULL;
        while(cur){
            ListNode*forw=cur->next;
            cur->next=prev;
            prev=cur;
            cur=forw;
        }
        return prev;
    }
    ListNode* doubleIt(ListNode* head) {
        ListNode*rev=rever(head);
        ListNode*x=rev;
        int carry=0;
        while(x){
           x->val*=2;
           x->val+=carry;
           carry=x->val/10;
           x->val%=10;
           if(x->next==NULL){
            if(carry){
                x->next=new ListNode(carry);
                x=x->next;
            }
           }
           x=x->next;
        }
        if(carry){
            x=new ListNode(carry);
            x=x->next;
        }

        return rever(rev);
        
    }
};