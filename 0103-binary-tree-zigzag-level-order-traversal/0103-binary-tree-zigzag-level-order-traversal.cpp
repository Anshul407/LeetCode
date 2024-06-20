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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(!root)return ans;
        bool left=1;
        queue<TreeNode*>q;

        q.push(root);
        while(!q.empty()){
            vector<int>temp;
            int size=q.size();
            for(int i=0;i<size;i++){
               
                    TreeNode*x=q.front();
                    q.pop();
                    temp.push_back(x->val);
                    if(x->left)q.push(x->left);
                    if(x->right)q.push(x->right);
               
                   
             
            }
            if(!left)reverse(temp.begin(),temp.end());
            left=!left;
            ans.push_back(temp);
        }
        return ans;
    }
};