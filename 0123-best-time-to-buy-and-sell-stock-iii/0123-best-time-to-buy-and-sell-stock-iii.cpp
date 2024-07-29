class Solution {
public:
    int solve(vector<int>& prices,int i,int cnt,bool buy,int n,vector<vector<vector<int>>> &dp){
        
        if(i>=n)return 0;
        if(dp[i][buy][cnt]!=-1)return dp[i][buy][cnt];

        int profit=0;
        if(buy){
            profit=max(-prices[i]+solve(prices,i+1,cnt,false,n,dp),solve(prices,i+1,cnt,true,n,dp));
        }
        else if(cnt<2){
            profit=max(prices[i]+solve(prices,i+1,cnt+1,true,n,dp),solve(prices,i+1,cnt,false,n,dp));
        }

        return dp[i][buy][cnt]=profit;
    }
    int maxProfit(vector<int>& prices) {
        bool buy=true;
        int cnt=0;
        vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>>(2, vector<int>(3, -1)));
        return solve(prices,0,cnt,buy,prices.size(),dp);

    }
};