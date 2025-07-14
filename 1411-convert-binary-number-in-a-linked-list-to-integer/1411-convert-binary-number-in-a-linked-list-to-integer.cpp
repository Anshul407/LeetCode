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
    ListNode*solve(ListNode*head){
        if(!head)return nullptr;
        ListNode*prev=NULL;
        ListNode*cur=head;
        while(cur){
            ListNode*forw=cur->next;
            cur->next=prev;
            prev=cur;
            cur=forw;
        }

        return prev;
    }
    int getDecimalValue(ListNode* head) {
       ListNode*rev=solve(head);
        int ans=0;
        int i=0;
       while(rev){
        ans+=(1<<i)*rev->val;
        rev=rev->next;

        i++;
       }
       return ans;
       
    }
};