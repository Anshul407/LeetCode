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
    void mp(TreeNode*root,int &sum){
        if(root==NULL){
            return ;
        }
        if(root->left!=NULL){
        TreeNode*x=root->left;
        if(x->left==NULL&&x->right==NULL){
            sum+=x->val;
        }}
        mp(root->left,sum);
        mp(root->right,sum);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int sum=0;
        mp(root,sum);
        return sum;
    }
};