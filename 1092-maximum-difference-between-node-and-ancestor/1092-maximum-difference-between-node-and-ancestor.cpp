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
    int f(TreeNode*root,int cur){
        if(!root)return 0;

        int op1=abs(cur-root->val);
        int op2=f(root->left,cur);
        int op3=f(root->right,cur);
        return max({op1,op2,op3});
    }
    int maxAncestorDiff(TreeNode* root) {
        if(!root)return 0;

        int cur=root->val;
        int s=f(root,cur);
        int op1=maxAncestorDiff(root->left);
        int op2=maxAncestorDiff(root->right);
        return max({s,op1,op2});
    }
};