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
    int check(TreeNode*root){
        if(!root)return 0;
        int op1=check(root->left);
        int op2=check(root->right);
        return 1+op1+op2;
    }
    bool solve(TreeNode*root,int i,int tot){
        if(!root)return 1;
        if(i>tot)return 0;
        return solve(root->left,2*i,tot)&&solve(root->right,2*i+1,tot);
    }
    bool isCompleteTree(TreeNode* root) {
        int totnodes=check(root);
        return solve(root,1,totnodes);
    }
};