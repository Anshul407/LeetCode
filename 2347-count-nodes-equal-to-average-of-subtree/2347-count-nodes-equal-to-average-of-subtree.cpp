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
    void solve(TreeNode*root,int &s,int &k){
        if(!root)return ;
        s+=root->val;
        k++;
        solve(root->left,s,k);
        solve(root->right,s,k);
    }
    int averageOfSubtree(TreeNode* root) {
        if(!root)return 0;
        int a=0,b=0;
        int s=0,t=0;
        solve(root->left,a,b);
        s+=a;
        t+=b;
        a=0,b=0;
        solve(root->right,a,b);
        s+=a;
        t+=b;
        s+=root->val;
        t++;
        int i=root->val==(s)/t;
        return i+averageOfSubtree(root->left)+averageOfSubtree(root->right);
    }
};