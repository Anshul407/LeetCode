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
    int s(TreeNode*root){
        if(!root)return 0;
        if(root->val==1)return 1;
        if(s(root->left))return 1;
        if(s(root->right))return 1;
        return 0;
    }
    TreeNode* pruneTree(TreeNode* root) {
        if(!root)return NULL;

       
        int f=root->val==1;
        if(!f){
            f=s(root->left);
            if(!f){
                f=s(root->right);
            }

        }
        root->left=pruneTree(root->left);
        root->right=pruneTree(root->right);
        if(!f)return NULL;
        return root;
    }
};