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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>v;
        map<int,map<int,vector<int>>>mp;
        queue<pair<TreeNode*,pair<int,int>>>q;
        q.push(make_pair(root,make_pair(0,0)));
        while(!q.empty()){
            pair<TreeNode*,pair<int,int>>t=q.front();
            q.pop();
            TreeNode* node=t.first;
            int hd=t.second.first;
            int lvl=t.second.second;
            mp[hd][lvl].push_back(node->val);
             sort(mp[hd][lvl].begin(), mp[hd][lvl].end());
            if(node->left){
               q.push(make_pair(node->left,make_pair(hd-1,lvl+1)));
            }
            if(node->right){
               q.push(make_pair(node->right,make_pair(hd+1,lvl+1)));
            }


        }
        for(auto i:mp){
            vector<int>ans;
            for(auto j:i.second){
                for(auto x:j.second){
                    ans.push_back(x);
                }
            }
           
            v.push_back(ans);
        }
        return v;
    }
};