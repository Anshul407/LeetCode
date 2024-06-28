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
    void dfs(TreeNode*root,vector<int>&res,int depth){
        if(root==NULL)return ;

        if(depth==res.size()){
            res.push_back(root->val);
        }else{
            res[depth]=max(root->val,res[depth]);
        }

        dfs(root->left,res,depth+1);
        dfs(root->right,res,depth+1);
    }
    vector<int> largestValues(TreeNode* root) {
        vector<int>ans;
        dfs(root,ans,0);
        return ans;
    }
};