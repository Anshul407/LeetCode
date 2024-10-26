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

    TreeNode* replaceValueInTree(TreeNode* root) {
        if(!root)return NULL;
        vector<int>lv;
        
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            auto s=q.size();
            int k=0;
            for(int i=0;i<s;i++){
                auto node=q.front();
                q.pop();
                k+=node->val;
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);

            }
            lv.push_back(k);
        }
        queue<pair<TreeNode*,int>>qq;
        qq.push({root,1});
        
        while(!qq.empty()){
            auto node=qq.front().first;
            auto c=qq.front().second;
            qq.pop();
            if(c>=lv.size())continue;
            int tot=lv[c];
            cout<<tot<<" ";
            if(node->left){
                tot-=node->left->val;
            }
            if(node->right){
                tot-=node->right->val;
            }
             if(node->left){
                node->left->val=tot;
                qq.push({node->left,c+1});
            }
            if(node->right){
                node->right->val=tot;
                qq.push({node->right,c+1});
            }

        }
        root->val=0;
        return root;
    }
};