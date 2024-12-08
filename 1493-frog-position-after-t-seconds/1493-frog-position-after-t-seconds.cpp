class Solution {
public:
double dfs(int i,map<int,vector<int>>&mp,int t,int d,vector<int>&vis){
        if(t==0)return i==d?1.0:0.0;
        double ans=0.0;
        vis[i]=1;
        int unv=0;
        for(auto v:mp[i]){
            if(vis[v]==0)unv++;
        }
        if(unv==0)return i==d?1.0:0.0;
        for(auto v:mp[i]){
            if(!vis[v]){
                double cur=(1.0/unv)*dfs(v,mp,t-1,d,vis);
                ans+=cur;
            }
        }
        return ans;
    }
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        map<int,vector<int>>mp;
        for(auto i:edges){
            mp[i[0]].push_back(i[1]);
            mp[i[1]].push_back(i[0]);
        }
        vector<int>vis(n+1,0);
        int s=0;
        return dfs(1,mp,t,target,vis);
    }
};