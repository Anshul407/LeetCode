class Solution {
public:
    int solve(vector<int>& cost,int i,vector<int>&dp){
        if(i>=cost.size())return 0;
        if(dp[i]!=-1)return dp[i];
        int c1=cost[i]+solve(cost,i+1,dp);
        int c2=cost[i]+solve(cost,i+2,dp);
        

        return dp[i]= min(c1,c2);

    }
    int minCostClimbingStairs(vector<int>& cost) {
        int i=0;
        
        int ans=0;
        vector<int>dp(cost.size(),-1);
        int x=solve(cost,i,dp);
        vector<int>dp2(cost.size(),-1);
        int y=solve(cost,1,dp2);
        return min(x,y);
    }
};