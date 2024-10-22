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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long>ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            long long s=0;
            for(int i=0;i<size;i++){
                auto node=q.front();
                q.pop();
                s=s+(long long)node->val;
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }
            ans.push_back(s);
        }
        sort(ans.begin(),ans.end());
        reverse(ans.begin(),ans.end());
        if(k>ans.size())return -1;
        return ans[k-1];
    }
};