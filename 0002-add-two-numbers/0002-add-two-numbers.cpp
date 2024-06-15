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
    ListNode* reverse(ListNode* head){
        ListNode*curr=head;
        ListNode*prev=NULL;
        while(curr){
            ListNode*fr=curr->next;
            curr->next=prev;
            prev=curr;
            curr=fr;
        }
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode*num1=l1;
        ListNode*num2=l2;
        ListNode*ans=NULL;
        ListNode*ans2=NULL;
        int carry=0;
        while(num1&&num2){
            int num=num1->val+num2->val;
            num+=carry;
            carry=num/10;
            num%=10;
            ListNode*x=new ListNode(num);
            if(!ans){
                ans=x;
                ans2=ans;
            }
            else{
                ans->next=x;
                ans=x;
            }
            num1=num1->next;
            num2=num2->next;

        }
       
            while(num1){
                int num=num1->val;
            num+=carry;
            carry=num/10;
            num%=10;
            ListNode*x=new ListNode(num);
            if(!ans){
                ans=x;
                ans2=ans;
            }
            else{
                ans->next=x;
                ans=x;
            }
            num1=num1->next;
            }
         while(num2){
                int num=num2->val;
            num+=carry;
            carry=num/10;
            num%=10;
            ListNode*x=new ListNode(num);
            if(!ans){
                ans=x;
                ans2=ans;
            }
            else{
                ans->next=x;
                ans=x;
            }
            num2=num2->next;
            }
            if(carry){
                ListNode*x=new ListNode(carry);
                 if(!ans){
                ans=x;
            }
            else{
                ans->next=x;
                ans=x;
            }
            }
      return ans2;
    }
};