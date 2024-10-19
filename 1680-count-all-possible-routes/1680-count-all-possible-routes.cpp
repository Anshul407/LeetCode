class Solution {
public:
    vector<vector<int>>dp;
    int mod=1e9+7;
    int solve(vector<int>& locations, int start, int finish, int fuel){
        if(fuel<0)return 0;
        if(dp[start][fuel]!=-1)return dp[start][fuel];
        int ans=(start==finish)?1:0;
        for(int i=0;i<locations.size();i++){
            if(i!=start){
                int cost=abs(locations[i]-locations[start]);
                if(cost<=fuel)
                ans=(ans+countRoutes(locations,i,finish,fuel-cost))%mod; 
            }  
        }
        return dp[start][fuel]=ans;
    }
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
       dp.resize(locations.size(),vector<int>(fuel+1,-1));
        return solve(locations,start,finish,fuel);
    }
};