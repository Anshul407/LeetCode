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
     map<TreeNode*,TreeNode*>mp;
    int f(TreeNode*r){
        if(!r)return 0;
        return 1+max(f(r->left),f(r->right));
    }
    TreeNode*solve(TreeNode*root,int h){
        if(!root)return NULL;
        if(h==1){
            return root;
        }
        if(root->left)mp[root->left]=root;
        if(root->right)mp[root->right]=root;
        auto l= solve(root->left,h-1);
        
        auto r=solve(root->right,h-1);
        if(l&&r)return root;
        if(l)return l;
        return r;
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        int h=f(root);
        

        return solve(root,h);
    }
};