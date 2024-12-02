/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void f(TreeNode*root,int &s){
        if(!root)return ;
        s+=root->val;
        f(root->left,s);
        f(root->right,s);
    }
    void solve(TreeNode*root,map<int,int>&mp){
        if(!root)return ;
        int l=0;
        f(root,l);
        mp[l]++;
        solve(root->left,mp);
        solve(root->right,mp);
    }
    
    vector<int> findFrequentTreeSum(TreeNode* root) {
        map<int,int>mp;
        solve(root,mp);
        vector<int>ans;
        int x=0;
        for(auto i:mp){
            x=max(x,i.second);
        }
        for(auto i:mp){
            if(i.second==x)ans.push_back(i.first);
        }
        return ans;
    }
};