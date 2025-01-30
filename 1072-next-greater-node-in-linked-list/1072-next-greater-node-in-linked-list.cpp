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
    vector<int> nextLargerNodes(ListNode* head) {
        stack<pair<int,int>>st;
        vector<int>v;
        ListNode*temp=head;
        int s=0;
        int cur=0;
        while(temp){
            s++;
            temp=temp->next;
        }v.resize(s,0);
        temp=head;
        while(temp){
            while(!st.empty()&&st.top().second<temp->val){
                v[st.top().first]=temp->val;
                st.pop();
            }
            st.push({cur,temp->val});
            temp=temp->next;
            cur++;
        }return v;
    }
};