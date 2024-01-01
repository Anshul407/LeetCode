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

    bool mp(TreeNode*root,long long small,long long large){
        if(root==NULL){
        
            return true;

        }
        return (root->val>small&&root->val<large) &&mp(root->left,small,root->val)&&mp(root->right,root->val,large);
    }
    bool isValidBST(TreeNode* root) {
        long long small=LONG_MIN;
        long long large=LONG_MAX;
        
        return mp(root,small,large);
        
    }
};