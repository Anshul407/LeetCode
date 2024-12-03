class Solution {
public:
   bool solve(int i,map<int,vector<int>>&mp,int c,vector<int>&vis){
    vis[i]=c;
    for(auto v:mp[i]){
        if(vis[v]==c)return 1;
        if(vis[v]==-1)
        if(solve(v,mp,!c,vis))return 1;
    }
    return 0;
   }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        map<int,vector<int>>mp;
        for(auto i:dislikes){
            mp[i[0]].push_back(i[1]);
            mp[i[1]].push_back(i[0]);
        }
        vector<int>vis(n+1,-1);
        for(int i=1;i<=n;i++){
            if(vis[i]==-1){
                if(solve(i,mp,1,vis))return 0;
            }
        }
        return 1;
    }
};