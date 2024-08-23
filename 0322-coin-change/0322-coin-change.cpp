class Solution {
public:
    
    int solve(vector<int>&coins,int i,int k,vector<vector<int>>&dp,int amt){
       if(k==amt)return 0;
       if(i>=coins.size())return INT_MAX;
        if(dp[i][amt]!=-1)return dp[i][amt];
        int tk=INT_MAX,ntk=INT_MAX;
        if(coins[i]+amt<=k)
         tk=solve(coins,i,k,dp,amt+coins[i]);
         if(tk!=INT_MAX)tk++;
         ntk=solve(coins,i+1,k,dp,amt);

        return dp[i][amt]=min(tk,ntk);
    }
    int coinChange(vector<int>& coins, int amount) {
        int amt=0;
        vector<vector<int>>dp(coins.size(),vector<int>(amount+1,-1));
        int ans= solve(coins,0,amount,dp,amt);
        if(ans==INT_MAX)return -1;
        return ans;
    }
};