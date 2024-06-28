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
    TreeNode* solve(TreeNode* root, vector<int>& to_delete, vector<TreeNode*>&ans){
        if(root==NULL){
            return NULL;
        }
        root->left=solve(root->left,to_delete,ans);
        root->right=solve(root->right,to_delete,ans);
        for(int i=0;i< to_delete.size();i++){
            if(root->val==to_delete[i]){
                if(root->left){
                    ans.push_back(root->left);
                
                }
                if(root->right){
                    ans.push_back(root->right);
                
                }
        
                return NULL;
            }
        }
        
        return root;
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*>ans;
        TreeNode* x=solve(root,to_delete,ans);
       
        for(int i=0;i<to_delete.size();i++){
            if(root->val==to_delete[i])return ans;
        }
         ans.push_back(root);
        return ans;
    }
};