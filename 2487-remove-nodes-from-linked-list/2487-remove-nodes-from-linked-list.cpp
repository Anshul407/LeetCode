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
        if(head==NULL||head->next==NULL)return head;

        ListNode*x =reverse(head->next);
        head->next->next=head;
        head->next=NULL;
        return x;
    }
    ListNode* removeNodes(ListNode* head) {
        ListNode* newhead= reverse(head);
        ListNode*temp=newhead;
        int maxi=temp->val;
        while(temp!=NULL&&temp->next!=NULL){
              maxi=max(maxi,temp->next->val);
              
              if(temp->next->val<maxi){
                temp->next=temp->next->next;
              }else
              temp=temp->next;

        }
        return reverse(newhead);

        
    }
};