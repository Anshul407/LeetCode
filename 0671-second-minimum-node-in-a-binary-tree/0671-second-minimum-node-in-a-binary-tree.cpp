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
    void findmini(TreeNode*root,int &mini){
        if(root==NULL){
            return ;
        }
        mini=min(mini,root->val);
        findmini(root->left,mini);
        findmini(root->right,mini);
    }
    void findmini2(TreeNode*root,int &mini,int mini1,int &flag){
        if(root==NULL){
            return ;
        }
        if(root->val!=mini1){
mini=min(mini,root->val);
flag=0;
        }
        
        findmini2(root->left,mini,mini1,flag);
        findmini2(root->right,mini,mini1,flag);
    }
    int findSecondMinimumValue(TreeNode* root) {
        int mini1=INT_MAX,mini2=INT_MAX,flag=1;
        findmini(root,mini1);
        findmini2(root,mini2,mini1,flag);
        if(mini2==INT_MAX&&flag)return -1;
        return mini2;
    }
};