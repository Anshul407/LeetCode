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
    void solve(TreeNode*root,string &ans,string word){
        if(root==NULL){
            return ;
        }
        if(root->left==NULL&&root->right==NULL){
            char x=char(root->val+97);
            word.push_back(x);
            cout<<x;
            reverse(word.begin(),word.end());
           
            if(ans==""){
                ans=word;
            }else{
                if(word<ans){
                    ans=word;
                }
            }
            return ;
        }
        char x=char(root->val+97);
        word.push_back(x);
        solve(root->left,ans,word);
        solve(root->right,ans,word);

    }
    string smallestFromLeaf(TreeNode* root) {
        string ans="";
        string word="";
        solve(root,ans,word);
        return ans;
    }
};