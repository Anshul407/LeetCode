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
    void solve(TreeNode*root,int &ans,int cur){
        if(!root){return ;
        }
        if(root->val>=cur){
            ans++;
            cur=root->val;
        }
        solve(root->left,ans,cur);

        solve(root->right,ans,cur);
    }
    int goodNodes(TreeNode* root) {
        int ans=0,cur=root->val;
        solve(root->left,ans,cur);
        solve(root->right,ans,cur);

        return ans+1;
    }
};