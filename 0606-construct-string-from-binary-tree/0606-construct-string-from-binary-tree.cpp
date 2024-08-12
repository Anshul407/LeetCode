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
    void solve(TreeNode*root,string &temp){
        if(root==NULL){
            return ;
        }
        
        

        temp+="(";
        temp+=to_string(root->val);
        
        solve(root->left,temp);
       if(!root->left&&root->right)temp+="()";
       
        solve(root->right,temp);

        temp+=")";
    }
    string tree2str(TreeNode* root) {
        string temp="";
        temp+=to_string(root->val);
        if(!root->left&&root->right)temp+="()";
        solve(root->left,temp);
         solve(root->right,temp);
        return temp;
    }
};