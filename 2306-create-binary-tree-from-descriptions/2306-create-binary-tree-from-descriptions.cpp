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
    TreeNode*solve(unordered_map<int,vector<pair<int,int>>>&mp,int i,unordered_map<int,int>&mp2){
        if(mp2.find(i)==mp2.end())return NULL;
        TreeNode*root=new TreeNode(i);
        int l=-1,r=-1;
        for(auto v:mp[i]){
            if(v.second)l=v.first;
            else r=v.first;
        }
        root->left=solve(mp,l,mp2);
        root->right=solve(mp,r,mp2);
        return root;
    }
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,vector<pair<int,int>>>mp;
        int p=0;
        unordered_map<int,int>mp2;
        for(auto i:descriptions){
            mp[i[0]].push_back({i[1],i[2]});
            mp2[i[1]]=1;
        }
        for(auto i:mp){
            if(mp2.find(i.first)==mp2.end()){
                p=i.first;
                break;
            }
        }
        mp2[p]=1;
        return solve(mp,p,mp2);

        
    }
};