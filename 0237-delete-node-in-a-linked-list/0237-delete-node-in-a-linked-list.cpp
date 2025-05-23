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
    void deleteNode(ListNode* node) {
        if(node->next==NULL){
            auto temp=node;
            delete temp;
            return ;
        }
        node->val=node->next->val;
        auto temp=node->next;
        node->next=node->next->next;
        delete temp;

    }
};