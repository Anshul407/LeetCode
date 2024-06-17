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
    pair<int,int> diameter(TreeNode*root){
        if(root==NULL){
            pair<int,int>p;
            p.first=0,p.second=0;
            return p;
        }
        pair<int,int>left=diameter(root->left);
        pair<int,int>right=diameter(root->right);
        int op1=left.first;
        int op2=right.first;
        int op3=left.second+right.second;

        pair<int,int>ans;
        ans.first=max(op1,max(op2,op3));
        ans.second=1+max(left.second,right.second);
        return ans;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        return diameter(root).first;
    }
};