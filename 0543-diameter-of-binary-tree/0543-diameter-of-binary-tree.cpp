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
    unordered_map<TreeNode*,int>dp;
    int ht(TreeNode*root){
        if(!root)return 0;
        if(dp.count(root))return dp[root];
        return dp[root]=1+max(ht(root->left),ht(root->right));
    }
    int solve(TreeNode*root){
        if(!root)return 0;
        auto cur=ht(root->left)+ht(root->right);
        return max({cur,solve(root->left),solve(root->right)});
    }
    int diameterOfBinaryTree(TreeNode* root) {
        ht(root);
        return solve(root);
    }
};