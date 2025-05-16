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
    ListNode* middleNode(ListNode* head) {
        auto cur=head;
        auto cur2=head->next;
        while(cur&&cur2){
            cur=cur->next;
            cur2=cur2->next;
            if(cur2)cur2=cur2->next;
        }return cur;
    }
};