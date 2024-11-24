class Solution {
public:
    void solve(int i,vector<int>&vis,map<int,vector<int>>&mp){
        vis[i]=1;
        for(auto v:mp[i]){
            if(!vis[v]){
                solve(v,vis,mp);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        map<int,vector<int>>mp;
        int j=0;
        for(int i=0;i<isConnected.size();i++){
            for(int j=0;j<isConnected.size();j++){
                if(isConnected[i][j]){
                    mp[i].push_back(j);
                    mp[j].push_back(i);
                }
            }
        }
        int ans=0;
        vector<int>vis(isConnected.size(),0);
        for(int i=0;i<isConnected.size();i++){
            if(!vis[i]){
                ans++;
                solve(i,vis,mp);
            }
        }
        return ans;
    }
};