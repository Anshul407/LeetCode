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
    bool solve(TreeNode*root,int x,int l){
        if(!root)return 0;
        if(!root->left&&!root->right){
            return x+root->val>=l;
        }
        bool lef=solve(root->left,x+root->val,l);
        bool rig=solve(root->right,x+root->val,l);
        if(!lef)root->left=nullptr;
        if(!rig)root->right=nullptr;
        return lef||rig;

    }
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        if(root==NULL)return nullptr;
        if(!solve(root,0,limit))return nullptr;
        return root;

    }
};