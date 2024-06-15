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
    ListNode* sortList(ListNode* head) {
        ListNode*temp=head;
        while(temp){
            ListNode*min=temp;
            ListNode*temp2=temp->next;
            while(temp2){
                if(temp2->val<min->val){
                    min=temp2;
                }
                temp2=temp2->next;
            }
            int x=min->val;
            min->val=temp->val;
            temp->val=x;
            temp=temp->next;
        }
        return head;
    }
};