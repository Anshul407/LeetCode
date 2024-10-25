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
    bool checkone(TreeNode*root){
        if(!root)return 0;
        if(root->val==1)return 1;
        return checkone(root->left)||checkone(root->right);
    }
    TreeNode* pruneTree(TreeNode* root) {
        if(root==NULL)return NULL;
        if(!checkone(root->left)){
            root->left=NULL;
        }
        if(!checkone(root->right)){
            root->right=NULL;
        }
        pruneTree(root->left);
        pruneTree(root->right);
        if(root->left==NULL&&root->right==NULL&&root->val==0)return NULL;

        return root;

    }
};