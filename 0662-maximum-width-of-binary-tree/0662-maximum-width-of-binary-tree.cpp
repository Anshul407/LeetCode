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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        int maxi=0;
        while(!q.empty()){
            int size=q.size();
            auto left=q.front();
            auto right=q.back();
            maxi=max(maxi,(right.second-left.second)+1);

            for(int i=0;i<size;i++){
                auto it=q.front();
                auto Node=it.first;
                auto ind=it.second;
                q.pop();
                if(Node->left){
                    q.push({Node->left,(ind*2)+1});
                }
                if(Node->right){
                    q.push({Node->right,(ind*2)+2});
                }
            }

        }
        return maxi;
    }
};