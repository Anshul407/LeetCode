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
    ListNode* reverse(ListNode* head,int k){
        if(head==NULL){
            return head;
        }
        ListNode*cursor=head;
        for(int i=0;i<k;i++){
             if(cursor==NULL)return head;
             cursor=cursor->next;
        }
         ListNode*forward=NULL;
        ListNode*curr=head;
        ListNode*prev=NULL;
        int c=0;
        while(curr!=NULL&&c<k){
              forward=curr->next;
              curr->next=prev;
              prev=curr;
              curr=forward;
              c++;
        }
        
        if(forward!=NULL)
        head->next =reverse(forward,k);
       
        return prev;
        
    
        
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
    
       return reverse(head,k);
       

      
        
    }
};