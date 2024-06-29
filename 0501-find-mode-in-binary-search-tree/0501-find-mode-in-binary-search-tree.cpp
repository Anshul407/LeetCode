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
    vector<int>ans;
    int currdata=-1;
    int currfreq=0;
    int maxfreq=0;
    void inorder(TreeNode*root){
          if(root==NULL)return ;

          inorder(root->left);
            
          if(currdata==root->val){
            currfreq++;
          }else{
            currfreq=1;
            currdata=root->val;
          }

          if(currfreq>maxfreq){
            maxfreq=currfreq;
            ans={};
          }

          if(currfreq==maxfreq){
            ans.push_back(currdata);
          }



          inorder(root->right);
    }
    vector<int> findMode(TreeNode* root) {
    
        inorder(root);
        return ans;
        
      
    }
};