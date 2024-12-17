class Solution {
public:
    bool dfs(TreeNode* root,long l,long r)
    {
        if(root==NULL)
        return true;
        if(root->val<=l||root->val>=r)return 0;
        return dfs(root->left,l,root->val)&&dfs(root->right,root->val,r);
    }
    bool isValidBST(TreeNode* root) {
        return dfs(root,LONG_MIN,LONG_MAX);
    }
};