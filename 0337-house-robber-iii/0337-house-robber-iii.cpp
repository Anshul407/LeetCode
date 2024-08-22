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
    vector<int>solve(TreeNode*root){
        if(!root){
            return {0,0};
        }
        auto left=solve(root->left);
        auto right=solve(root->right);

        int inc=root->val+left[1]+right[1];
        int ntinc=max(left[1],left[0])+max(right[1],right[0]);

        return {inc,ntinc};
    }
    int rob(TreeNode* root) {
        auto it=solve(root);
        return max(it[0],it[1]);
    }
};