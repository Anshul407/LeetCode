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
    void mp(TreeNode*root,int &ans,int &prev){
        if(root==NULL){
            ans=1;
            return;

        }
        mp(root->left,ans,prev);

        if(root->val<prev){
            ans=0;
            return ;
        }
        else{
            prev=root->val; 
            ans=1;
        }
        mp(root->right,ans,prev);
    }
    bool isValidBST(TreeNode* root) {
        int prev=INT_MIN;
        int ans=0;
        mp(root,ans,prev);
        return ans;
    }
};