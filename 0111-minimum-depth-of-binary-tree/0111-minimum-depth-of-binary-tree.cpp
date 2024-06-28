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
    void solve(TreeNode*root,int h,int &ans){
        if(root==NULL)return ;
        if(!root->left&&!root->right){
            ans=min(ans,h);
        }
        solve(root->left,h+1,ans);
        solve(root->right,h+1,ans);
    }
    int minDepth(TreeNode* root) {
        if(root==NULL)return 0;
        int h=1;
        int ans=INT_MAX;
        solve(root,h,ans);
        return ans;
    }
};