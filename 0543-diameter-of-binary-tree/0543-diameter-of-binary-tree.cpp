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
    int f(TreeNode*root){
        if(!root)return 0;

        return 1+max(f(root->left),f(root->right));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root)return 0;
        int lh=f(root->left);
        int rh=f(root->right);
        int ld=diameterOfBinaryTree(root->left);
        int rd=diameterOfBinaryTree(root->right);

        return max({lh+rh,ld,rd});
    }
};