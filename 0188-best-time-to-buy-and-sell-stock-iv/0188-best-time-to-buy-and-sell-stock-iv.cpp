class Solution {
public:
    int solve(vector<int>& prices,int i,int k,bool buy,vector<vector<vector<int>>>&dp,int n){
        if(k==0)return 0;
        
        if(i>=n)return 0;
        if(dp[i][buy][k]!=-1)return dp[i][buy][k];
        int profit=0;

        if(buy){
            profit=max(-prices[i]+solve(prices,i+1,k,false,dp,n),solve(prices,i+1,k,true,dp,n));
        }
        else {
            profit=max(prices[i]+solve(prices,i+1,k-1,true,dp,n),solve(prices,i+1,k,false,dp,n));
        }

        return dp[i][buy][k]=profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<vector<int>>>dp(prices.size(),vector<vector<int>>(2,vector<int>(k+1,-1)));
        bool buy=true;
        return solve(prices,0,k,buy,dp,prices.size());
    }
};