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
    void mp(TreeNode*root,int &ans,long &prev){
        if(root==NULL){
        
            return;

        }
        mp(root->left,ans,prev);

        if(root->val<=prev){
            ans=0;
            return ;
        }
        else{
            prev=root->val; 
           
        }
        mp(root->right,ans,prev);
    }
    bool isValidBST(TreeNode* root) {
        long prev=LONG_MIN;
        int ans=1;
        mp(root,ans,prev);
        return ans;
    }
};