class Solution {
public:
    long long ans;
    long long dfs(unordered_map<int,vector<int>>&mp,int i,vector<int>&vis,int s){
        vis[i]=1;
        long long cnt=1;
        for(auto v:mp[i]){
            if(!vis[v]){
                cnt+=dfs(mp,v,vis,s);
            }
        }
      
        if(i!=0){
        ans+=cnt/s;
        if(cnt%s)ans++;}
        return cnt;
    }
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        ans=0;
        unordered_map<int,vector<int>>mp;
        for(auto i:roads){
            mp[i[0]].push_back(i[1]);
            mp[i[1]].push_back(i[0]);
        }
        vector<int>vis(roads.size()+1,0);

        dfs(mp,0,vis,seats);
        return ans;

        
    }
};