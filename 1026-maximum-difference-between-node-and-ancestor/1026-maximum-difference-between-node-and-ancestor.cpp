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
    int solve(TreeNode*root,int mini,int maxi){
        if(!root)return maxi-mini;

        mini=min(mini,root->val);
        maxi=max(maxi,root->val);
        int leftkaans=solve(root->left,mini,maxi);
        int rightkaans=solve(root->right,mini,maxi);

        return max(leftkaans,rightkaans);
    }
    int maxAncestorDiff(TreeNode* root) {
        return solve(root,root->val,root->val);
    }
};