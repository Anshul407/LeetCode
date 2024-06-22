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
    void solve(TreeNode* root,vector<int>path, int targetSum,int &ans){
        if(root==NULL)return ;

        path.push_back(root->val);
        solve(root->left,path,targetSum,ans);
        solve(root->right,path,targetSum,ans);

        for(int i=path.size()-1;i>=0;i--){
            targetSum-=path[i];
            if(targetSum==0)ans=ans+1;
        }
    }
    int pathSum(TreeNode* root, int targetSum) {
        int ans=0;
        vector<int>path;
        solve(root,path,targetSum,ans);
        return ans;
    }
};