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
    int f(TreeNode*root){
        if(!root)return 0;
        int l=f(root->left);
        int r=f(root->right);
        return 1+max(l,r);
    }
    void solve(TreeNode*root,vector<vector<string>>&ans,int lv,int w,int h){
        if(!root)return ;
        ans[lv][w]=to_string(root->val);
        int off=pow(2,h-lv-1);
        solve(root->left,ans,lv+1,w-off,h);
        solve(root->right,ans,lv+1,w+off,h); 
    }
    vector<vector<string>> printTree(TreeNode* root) {
        int h=f(root)-1;
        int len=(1<<h+1)-1;
        vector<vector<string>>ans(h+1,vector<string>(len,""));
        solve(root,ans,0,(len-1)/2,h);
        return ans;
    }
};