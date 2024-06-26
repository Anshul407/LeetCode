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
    void solve(TreeNode*root,string word,vector<string> &ans){
        if(root==NULL){
            return ;
        }
        if(!root->left&&!root->right){
            word+=to_string(root->val);
            ans.push_back(word);
            return ;

        }
        word+=to_string(root->val);
        word+="->";
        solve(root->left,word,ans);
        solve(root->right,word,ans);



    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
        string word="";
        solve(root,word,ans);
        return ans;

    }
};