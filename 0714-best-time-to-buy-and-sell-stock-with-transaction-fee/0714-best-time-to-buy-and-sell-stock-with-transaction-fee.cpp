class Solution {
public:
    int solve(vector<int>prices,int i,int fee,bool buy,int n,vector<vector<int>>&dp){
        if(i>=n)return 0;

        if(dp[i][buy]!=-1)return dp[i][buy];
        int profit=0;
        if(buy){
            profit=max(-prices[i]+solve(prices,i+1,fee,false,n,dp),solve(prices,i+1,fee,true,n,dp));
        }else{
            profit=max(prices[i]-fee+solve(prices,i+1,fee,true,n,dp),solve(prices,i+1,fee,false,n,dp));
        }

        return dp[i][buy]=profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>>dp(prices.size(),vector<int>(2,-1));
        int i=0;
        int n=prices.size();
        return solve(prices,i,fee,true,n,dp);
    }
};