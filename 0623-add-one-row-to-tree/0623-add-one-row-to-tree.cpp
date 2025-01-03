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
    TreeNode*solve(TreeNode*root,int val,int d){
        if(!root)return NULL;
        root->left=solve(root->left,val,d-1);
        root->right=solve(root->right,val,d-1);
        if(d==1){
                TreeNode*temp=root->left;
                root->left=new TreeNode(val);
                root->left->left=temp;
                temp=root->right;
                root->right=new TreeNode(val);;
                root->right->right=temp;
        }
        return root;
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        depth--;
        if(depth==0){
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }
        return solve(root,val,depth);
    }
};