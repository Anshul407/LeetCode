class Solution {
public:
    
    
    int solve(vector<vector<int>>& offers,int i,int p,vector<vector<int>>&dp){
        if(i>=offers.size())return 0;
        if(dp[i][p+1]!=-1)return dp[i][p+1];
        int tk=0;
        if(p<offers[i][0])
        tk=offers[i][2]+solve(offers,i+1,offers[i][1],dp);
        
        int ntk=solve(offers,i+1,p,dp);

        return dp[i][p+1] =max(tk,ntk);
    }
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        vector<vector<int>>dp(offers.size(),vector<int>(n+1,-1));
        sort(offers.begin(),offers.end());
        return solve(offers,0,-1,dp);
    }
};