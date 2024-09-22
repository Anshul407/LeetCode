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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode*num1=rever(l1);
        ListNode*num2=rever(l2);
        int carry=0;
        ListNode*ans=new ListNode(0);
        ListNode*temp=ans;
        while(num1&&num2){
            int num=num1->val+num2->val+carry;
            carry=num/10;
            num%=10;
            temp->next=new ListNode(num);
            temp=temp->next;
            num1=num1->next;
            num2=num2->next;
        }
        while(num1){
            int num=num1->val+carry;
            carry=num/10;
            num%=10;
            temp->next=new ListNode(num);
            temp=temp->next;
            num1=num1->next;
        }
         while(num2){
            int num=num2->val+carry;
            carry=num/10;
            num%=10;
            temp->next=new ListNode(num);
            temp=temp->next;
            num2=num2->next;
        }
        if(carry){
            temp->next=new ListNode(carry);
            temp=temp->next;
        }

        return rever(ans->next);
    }
};