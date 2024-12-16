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
    map<int,vector<pair<int,char>>>mp;
    void f(TreeNode*root){
        if(!root)return ;
        if(root->left){
            mp[root->val].push_back({root->left->val,'L'});
            mp[root->left->val].push_back({root->val,'U'});
            f(root->left);
        }
        if(root->right){
            mp[root->val].push_back({root->right->val,'R'});
            mp[root->right->val].push_back({root->val,'U'});
            f(root->right);
        }
        
        
    }
    bool solve(int i,int j,vector<int>&vis,string &a){
        if(i==j)return 1;
        vis[i]=1;
        
        for(auto v:mp[i]){
            if(!vis[v.first]){
                a.push_back(v.second);
                int ans=solve(v.first,j,vis,a);
                if(ans)return 1;
                a.pop_back();
            }
        }
        return 0;
    }
    string getDirections(TreeNode* root, int st, int dest) {
        f(root);
        vector<int>vis(mp.size()+1,0);
        string ans="";
        solve(st,dest,vis,ans);
        return ans;
    }
};