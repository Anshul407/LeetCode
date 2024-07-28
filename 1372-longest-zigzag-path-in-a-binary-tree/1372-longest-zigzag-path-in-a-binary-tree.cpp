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
    void solve(TreeNode*root,int &ans,int h,char d){
        if(root==NULL)return ;
         ans=max(ans,h);
        solve(root->left,ans,1,d);
        solve(root->right,ans,1,d);
        if(root->left){
            if(d=='r')
            solve(root->left,ans,h+1,'l');
            else solve(root->left,ans,1,'l');
        }
        if(root->right){
            if(d=='l')
            solve(root->right,ans,h+1,'r');
            else solve(root->right,ans,1,'r');
            
        }
    }
    int longestZigZag(TreeNode* root) {
        int h=0,ans=0;
        char ch='X';
        solve(root,ans,h,ch);
        return ans;
    }
};