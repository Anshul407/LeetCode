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
    int ans;
    void solve(TreeNode*root,char c,int x){
        if(!root)return ;
        ans=max(ans,x);
        if(root->left){
            if(c=='r')solve(root->left,'l',x+1);
            else solve(root->left,'l',1);
        }
        if(root->right){
            if(c=='l')solve(root->right,'r',x+1);
            else solve(root->right,'r',1);
        }
    }
    int longestZigZag(TreeNode* root) {
        if(!root)return 0;
        solve(root,'p',0);
        return ans;
    }
};