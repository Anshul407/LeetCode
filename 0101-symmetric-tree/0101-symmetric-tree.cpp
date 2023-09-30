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
 bool mp(TreeNode*left,TreeNode*right){
     if(left==NULL||right==NULL)return left==right;

    

      return(left->val == right->val) && mp(left->left, right->right) && mp(left->right, right->left);


}
    bool isSymmetric(TreeNode* root) {
        if(!root)return true;
        
       return mp(root->left,root->right);
        
    
        
    }
};