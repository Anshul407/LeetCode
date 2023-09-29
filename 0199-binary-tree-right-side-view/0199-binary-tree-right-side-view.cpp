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
    void mp(TreeNode*node,int l,vector<int>&v){
        if(node==NULL)return ;

         

         if(v.size()==l)v.push_back(node->val);

        mp(node->right,l+1,v);
        mp(node->left,l+1,v);
    }
    vector<int> rightSideView(TreeNode* root) {
        int l=0;
        vector<int>v;
        if(root==NULL)return v;
        mp(root,l,v);
        return v;
    }
};