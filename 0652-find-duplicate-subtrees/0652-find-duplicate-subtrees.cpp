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
    string f(TreeNode*root){
        if(!root)return "N";
        string k=to_string(root->val);
        k+=",";
        k+=f(root->left);
        k+=",";
        k+=f(root->right);
        return k;
    }
    string solve(TreeNode*root,map<string,int>&mp,vector<TreeNode*>&ans){
        if(!root)return "N";
        string s=to_string(root->val)+","+solve(root->left,mp,ans)+","+solve(root->right,mp,ans);
        if(mp[s]==1){
            ans.push_back(root);
        }
        mp[s]++;
        return s;
       
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*>ans;
        map<string,int>mp;
        solve(root,mp,ans);
        return ans;
    }
};