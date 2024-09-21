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
    void solve(ListNode*temp,vector<int>&x,int i,int j,int c){
        if(i>j)return ;
        if(!c){
        temp->val=x[i];
        solve(temp->next,x,i+1,j,!c);
        }
        else{ temp->val=x[j];
        solve(temp->next,x,i,j-1,!c);}
    }
    void reorderList(ListNode* head) {
        vector<int>x;
        ListNode*temp=head;
        while(temp){
            x.push_back(temp->val);
            temp=temp->next;
        }
        ListNode* temp2=head;
        solve(temp2,x,0,x.size()-1,0);

        return ;
    
    }
};