class Solution {
public:
    int solve(vector<int>&c,int i,long long amt,int x,vector<vector<int>>&dp){
        if(amt==x)return 0;
        if(i>=c.size())return INT_MAX;
        if(dp[i][amt]!=-1)return dp[i][amt];
        int tk=INT_MAX,nttk=INT_MAX;
        if(c[i]+amt<=x){
            tk=solve(c,i,amt+c[i],x,dp);
            if(tk!=INT_MAX)tk++;
        }
        nttk=solve(c,i+1,amt,x,dp);

        return dp[i][amt]=min(tk,nttk);
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>>dp(coins.size(),vector<int>(amount,-1));

        int ans=solve(coins,0,0,amount,dp);
        return ans==INT_MAX?-1:ans;
    }
};