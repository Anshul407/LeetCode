class Solution {
public:
    int solve(vector<int>&s,int i,int m,int size,vector<vector<int>>&dp)
    {
        if(i>=s.size())return 0;
        int tk=0,nttk=0;
        if(dp[i][size]!=-1)return dp[i][size];
        tk=(s[i]*m)+solve(s,i+1,m+1,size+1,dp);
        nttk=solve(s,i+1,m,size,dp);

        return dp[i][size]= max(tk,nttk);
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(),satisfaction.end());
        vector<vector<int>>dp(satisfaction.size(),vector<int>(satisfaction.size(),-1));
        return solve(satisfaction,0,1,0,dp);
    }
};