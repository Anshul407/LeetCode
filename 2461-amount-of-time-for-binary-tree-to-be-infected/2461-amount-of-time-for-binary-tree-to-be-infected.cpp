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
    map<int,vector<int>>mp;
    void f(TreeNode*root){
        if(!root)return ;
        if(root->left){
            mp[root->left->val].push_back(root->val);
            mp[root->val].push_back(root->left->val);
             f(root->left);
        }
        if(root->right){
            mp[root->right->val].push_back(root->val);
            mp[root->val].push_back(root->right->val);
            f(root->right);
        }
       
       
    }
    int solve(int st,int p){
        if(mp[st].size()==1&&mp[st][0]==p)return 0;
        int ans=0;
        for(auto i:mp[st]){
            if(i!=p){
                ans=max(ans,1+solve(i,st));
            }
        }return ans;
    }
    int amountOfTime(TreeNode* root, int start) {
        f(root);
        return solve(start,-1);
    }
};