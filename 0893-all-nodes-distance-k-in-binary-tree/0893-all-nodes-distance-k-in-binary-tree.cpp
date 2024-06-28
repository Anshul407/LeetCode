/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    void parent(TreeNode*root,map<TreeNode*,TreeNode*>&mp){
        if(root==NULL)return ;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            if(it->left){
                mp[it->left]=it;
                q.push(it->left);
            }
            if(it->right){
                mp[it->right]=it;
                q.push(it->right);
            }
        }
        return ;
    }
    void solve(TreeNode*curr,int k,map<TreeNode*,TreeNode*>mp,vector<int>&ans,map<TreeNode*,bool>&vis){
        if(curr==NULL)return ;

        if(k==0){
            ans.push_back(curr->val);
            return ;
        }
        if(!vis[curr->left]){
            vis[curr->left]=1;
        solve(curr->left,k-1,mp,ans,vis);}
        if(!vis[curr->right]){
            vis[curr->right]=1;
        solve(curr->right,k-1,mp,ans,vis);}
        if(mp.count(curr)&&!vis[mp[curr]]){
            vis[mp[curr]]=1;
            solve(mp[curr],k-1,mp,ans,vis);
        }


    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<TreeNode*,TreeNode*>mp;
        parent(root,mp);
        vector<int>ans;
        map<TreeNode*,bool>vis;
        if(root==NULL)return ans;
        vis[target]=1;
        solve(target,k,mp,ans,vis);
        
        // if(ans.size())ans.erase(ans.begin());
        return ans;
    }
};