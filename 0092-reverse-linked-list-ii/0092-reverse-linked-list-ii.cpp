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
   pair<ListNode*,ListNode*> reverse(ListNode*head,int n){
        
        ListNode*prev=NULL;
        ListNode*curr=head;
        while(curr&&n>=0){
            ListNode*forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
            n--;
        }
        pair<ListNode*,ListNode*>p;
        p.first=prev;
        p.second=curr;
        return p;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left-right==0||abs(left-right)==1)return head;
        if(head==NULL||head->next==NULL)return head;
     
         ListNode*temp=head;
         ListNode*temp2=head;
         ListNode*prev=NULL;
         
         int l=left;
         while(temp&&l>1){
            prev=temp;
            temp=temp->next;
            l--;
         }
         pair<ListNode*,ListNode*>data=reverse(temp,right-left);

         ListNode*mid=data.first;
         
         ListNode*tail=data.second;
         if(prev!=NULL){
            
            prev->next=mid;
            

            
         }
         else{
           
            prev=mid;
         }
       
         ListNode*ans=prev;
         while(ans&&ans->next)ans=ans->next;
         ans->next=tail;
         return prev;
          
         
    }
};