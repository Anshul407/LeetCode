class Solution {
public:
    int dfs(int i,map<int,vector<int>>&mp,int p,vector<bool>&h){
        int ans=0;
        for(auto v:mp[i]){
            if(v!=p){
                int curtime=dfs(v,mp,i,h);
                if(curtime>0||h[v]){
                    ans+=curtime+2;
                }
            }
        }
        return ans;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        map<int,vector<int>>mp;
        for(auto i:edges){
            mp[i[0]].push_back(i[1]);
            mp[i[1]].push_back(i[0]);
        }

        return dfs(0,mp,-1,hasApple);
    }
};