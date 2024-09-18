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
    void solve(ListNode*temp){
        if(temp==NULL||temp->next==NULL)return ;

        int val=temp->val;
        temp->val=temp->next->val;
        temp->next->val=val;

        solve(temp->next->next);

        
    }
    ListNode* swapPairs(ListNode* head) {
        ListNode*temp=head;
        solve(temp);
        return head;
    }
};