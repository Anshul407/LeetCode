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
    int gcd(int first,int second)
{
    while(second != 0)
    {
        int temp = second;
        second = first % second;
        first = temp;
    }
    return first;
}
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode*headd=head;
        while(headd&&headd->next){
            ListNode* temp=new ListNode(gcd(headd->val,headd->next->val));
            temp->next=headd->next;
            headd->next=temp;
            
            headd=headd->next->next;
        }
        return head;
    }
};