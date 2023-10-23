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
  void mp(TreeNode*root,int &num,int &ans){
      if(root==NULL)return ;
      num=num*10+root->val;
      if(root->left==NULL&&root->right==NULL)ans+=num;
      mp(root->left,num,ans);
      mp(root->right,num,ans);
      num=num/10;
  }
    int sumNumbers(TreeNode* root) {
        int num=0;
        int ans=0;
        mp(root,num,ans);
        return ans;

        
    }
};