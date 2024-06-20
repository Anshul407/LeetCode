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
    bool hasPathSum(TreeNode* root, int t) {
        if(root==NULL){
           
            return 0;
        }

        if(!root->left&&!root->right){
            t-=root->val;
            if(t==0)return 1;

            return 0;
        }

        bool leftkapart=hasPathSum(root->left,t-root->val);
        bool rightkapart=hasPathSum(root->right,t-root->val);

        return leftkapart||rightkapart;
    }
};