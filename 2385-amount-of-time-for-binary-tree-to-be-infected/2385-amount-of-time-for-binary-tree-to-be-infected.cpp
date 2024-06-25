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
    TreeNode* build( map<TreeNode*,TreeNode*>&mp,TreeNode*root,int start){
        queue<TreeNode*>q;
        q.push(root);
        TreeNode*ans=NULL;
        while(!q.empty()){
            auto it=q.front();
            q.pop();

            if(start==it->val)ans=it;

            if(it->left){
                q.push(it->left);
                mp[it->left]=it;
            }
            if(it->right){
                q.push(it->right);
                mp[it->right]=it;
            }

        }
        return ans;
    }
    int solve(TreeNode*st,map<TreeNode*,TreeNode*>mp){
        queue<TreeNode*>q;
        q.push(st);
        int ans=0;
        map<TreeNode*,bool>vis;
        vis[st] = true;
        while(!q.empty()){
            int flag=0;
            int size=q.size();
            for(int i=0;i<q.size();i++){
                auto it=q.front();
                q.pop();
                if(it->left&&!vis[it->left]){
                    q.push(it->left);
                    vis[it->left]=1;
                    flag=1;
                }
                if(it->right&&!vis[it->right]){
                q.push(it->right);
                vis[it->right]=1;
                flag=1;
                }
                if(mp[it]&&!vis[mp[it]]){
                    q.push(mp[it]);
                    vis[mp[it]]=1;
                    flag=1;
                }
                
                 
 
            }
            if(flag)ans++;
            
        }
        return ans;
    }
    int amountOfTime(TreeNode* root, int start) {
        if(root==NULL)return 0;
        map<TreeNode*,TreeNode*>mp;
        TreeNode*tar=build(mp,root,start);
        return solve(tar,mp);
    }
};