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
    int mp(TreeNode*node,int &n){
        if(node==NULL)return 0;

        int x= max(0,mp(node->left,n));
        int y=max(0,mp(node->right,n));

        n=max(n,x+y+node->val);

        return node->val+max(x,y);

    }
    int maxPathSum(TreeNode* root) {
        if(root==NULL)return 0;
        int n=INT_MIN;
        mp(root,n);
        return n;
    }
};