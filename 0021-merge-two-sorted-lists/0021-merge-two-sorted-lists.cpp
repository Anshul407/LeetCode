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
    ListNode* solve(ListNode* list1, ListNode* list2) {
        ListNode*temp=list2;
        ListNode*curr=list1->next;
        ListNode*prev=list1;
        if(!list1->next&&!list2->next)
        {
               prev->next=list2;
               prev=list2;
               return list1;
        }
        // if(!list2->next&&list1->next){
        //     ListNode*temp=list1;
        //     while(temp->next!=NULL)temp=temp->next;
        //     temp->next=list2;
        //     temp=list2;
        //     return list1;
        // }
       if(prev->next==NULL){
                while(temp){
                    prev->next=temp;
                    prev=temp;
                    temp=temp->next;
                }
            }
        while(curr!=NULL&&temp){
            if(prev->val<=temp->val&&temp->val<=curr->val){
                  ListNode*newdata=new ListNode(temp->val);
                  
                    newdata->next=prev->next;
                    prev->next=newdata;
                
                   prev=prev->next;
                  
                  temp=temp->next;
            }else{
                prev=curr;
                curr=curr->next;
            }
            if(prev->next==NULL){
                while(temp){
                    prev->next=temp;
                    prev=temp;
                    temp=temp->next;
                }
            }

        }
        return list1;
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1)return list2;
        if(!list2)return list1;
        
        if(list1->val<list2->val){
        return solve(list1,list2);}
        else{
            return solve(list2,list1);
        }
        
    }
};