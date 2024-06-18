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
        ListNode*temp=head;
        ListNode*temp2=head->next;
        while(temp&&temp->next){
            int data1=temp->val;
            int data2=temp->next->val;
            int gcd1=gcd(data1,data2);
            ListNode*newdata=new ListNode(gcd1);
            newdata->next=temp->next;
            temp->next=newdata;
            temp=temp->next->next;
            
        }
        return head;
    }
};