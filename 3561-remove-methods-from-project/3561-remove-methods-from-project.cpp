class Solution {
public:
    void dfs(map<int,vector<int>>&mp,int i,vector<int>&vis){
        vis[i]=1;
        for(auto v:mp[i]){
            if(!vis[v]){
                dfs(mp,v,vis);
            }
        }
    }
    bool check(map<int,vector<int>>&mp,int i,vector<int>&vis,vector<int>&ans){
       
        ans[i]=1;
        bool p=0;
        for(auto v:mp[i]){
            if(!vis[v]&&!ans[v])p=p||check(mp,v,vis,ans);
            else if(vis[v])return true;
        }
        return p;

    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
         map<int,vector<int>>mp;
         for(auto i:invocations){
            mp[i[0]].push_back(i[1]);
         }
         int flag=0;
         vector<int>ans(n,0);
         vector<int>vis(n,0);
         dfs(mp,k,vis);
         for(int i=0;i<n;i++){
            if(!vis[i]&&!ans[i]){
                flag=check(mp,i,vis,ans);
                if(flag)break;
            }
         }
         vector<int>x;
         if(flag){
            for(int i=0;i<n;i++){
                x.push_back(i);
            }
            return x;
         }
         for(int i=0;i<n;i++){
            if(ans[i])x.push_back(i);
         }
         return x;
         
    }
};