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
    void mp(TreeNode*root,vector<TreeNode*>&v){
        if(root==NULL)return ;
        v.push_back(root);
        mp(root->left,v);
        mp(root->right,v);
    }
    void x(TreeNode*&root,vector<TreeNode*>&v){
        int i;
        root=v[0];
        TreeNode*curr=root;
        for(i=0;i<v.size();i++){
             curr->left=NULL;
             curr->right=v[i];
             curr=v[i];
            
        }
        curr->left=NULL;
        curr->right=NULL;
    }
    void flatten(TreeNode* root) {
        if(root==NULL)return ;
        vector<TreeNode*>v;
        mp(root,v);
        
        x(root,v);


    }
};