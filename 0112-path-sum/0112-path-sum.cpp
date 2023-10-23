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
void mp(TreeNode*root,int ts,int &ls,int &x){
    if(root==NULL)return ;
    ls+=root->val;
    if(ls==ts&&root->left==NULL&&root->right==NULL)x=1;
    mp(root->left,ts,ls,x);
    mp(root->right,ts,ls,x);
    ls-=root->val;
}
    bool hasPathSum(TreeNode* root, int targetSum) {
       int ls=0;
       int x=0;
        mp(root,targetSum,ls,x);
        return x;
    }
};