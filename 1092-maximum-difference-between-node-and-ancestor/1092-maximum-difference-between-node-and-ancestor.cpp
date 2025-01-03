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
    int solve(TreeNode*root,int maxi,int mini){
        if(!root)return abs(mini-maxi);
        int op1=solve(root->left,max(maxi,root->val),min(mini,root->val));
        int op2=solve(root->right,max(maxi,root->val),min(mini,root->val));
        

        return max(op1,op2);
        
    }
    int maxAncestorDiff(TreeNode* root) {
        if(!root)return 0;
        int ans=0;
        return solve(root,root->val,root->val);
        
    }
};