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
    ListNode* deleteMiddle(ListNode* head) {
        if(!head||head->next==NULL)return nullptr;
        ListNode*f=head;
        ListNode*c=head;
        ListNode*x=head;
        while(f->next){
            f=f->next;
            if(f->next)f=f->next;
            x=c;
            c=c->next;
        }
        x->next=c->next;
        c->next=nullptr;
        delete c;
        return head;
    }
};