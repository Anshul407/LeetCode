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
int maxDepth(TreeNode* root) {
       if(root==NULL)return 0;

       int leftkaheight=maxDepth(root->left);
       int rightkaheight=maxDepth(root->right);
       int rootkaheight=1;
       int maxheight=rootkaheight+max(leftkaheight,rightkaheight);

       return maxheight;
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL)return 1;

        bool leftkapart=isBalanced(root->left);
        bool rightkapart=isBalanced(root->right);

        bool balcondition=abs(maxDepth(root->left)-maxDepth(root->right))<=1;

        return leftkapart&&rightkapart&&balcondition;
    }
};