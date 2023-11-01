/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode*temp=head;
        ListNode*t2=head;
        while(temp!=NULL&&temp->next!=NULL&&temp->next->next!=NULL){
            temp=temp->next->next;
            t2=t2->next;
            if(temp==t2)return true;
        }
        return false;
    }
};