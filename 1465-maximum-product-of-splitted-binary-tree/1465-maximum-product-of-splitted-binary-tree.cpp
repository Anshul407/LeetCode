/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     long long val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(long long x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(long long x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    const long long mod=1e9+7;
    map<TreeNode*,long long>dp;
    long long f(TreeNode*root){
        if(!root)return 0;
        if(dp.find(root)!=dp.end())return dp[root];
        return dp[root]=root->val+f(root->left)+f(root->right);
    }
    long long solve(TreeNode*root,long long cur){
        if(!root)return 1;
        cur+=root->val;
        long long left=f(root->left);
        long long right=f(root->right);
        long long x=((cur+left)*right);
        long long y=((cur+right)*left);
        long long op=max(x,y);

        long long op1=solve(root->left,cur+right);
        long long op2=solve(root->right,cur+left);

        return max({op,op1,op2});
    }
    int maxProduct(TreeNode* root) {
         f(root);
         return solve(root,0)%mod;
    }
};