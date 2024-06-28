/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL){
            return NULL;
        }

        if(root==p){
            return p;

        }
        if(root==q){
            return q;
        }
        TreeNode* leftkaans=lowestCommonAncestor(root->left,p,q);
        TreeNode* rightkaans=lowestCommonAncestor(root->right,p,q);
         if(!leftkaans&&!rightkaans)return NULL;
        if(leftkaans&&!rightkaans){
            return leftkaans;
        }
        if(!leftkaans&&rightkaans){
            return rightkaans;
        }

       else
            return root;
        
        


    }
};