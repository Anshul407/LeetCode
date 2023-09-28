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
    int findBottomLeftValue(TreeNode* root) {
        vector<int>v;
        if(root==NULL)return 0;
        queue<TreeNode*>q;
        q.push(root);
        TreeNode*node=root;
        while(!q.empty()){
            node=q.front();
            q.pop();
            if(node->right){
                q.push(node->right);

            }
            if(node->left){
                q.push(node->left);
            }
       }
       return node->val;

    }
};