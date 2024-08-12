class Solution {
public:
    int solve(vector<int>&a,int i,int p,int d,vector<int>&dp){
        if(i>=a.size())return 0;
        if(dp[p+1]!=-1)return dp[p+1];
        int tk=0;
        int ntk=0;
        if(p==-1||a[i]-a[p]==d){
            tk=1+solve(a,i+1,i,d,dp);
        }
        ntk=solve(a,i+1,p,d,dp);

        return dp[p+1]=max(tk,ntk);
    }
    int longestSubsequence(vector<int>& arr, int difference) {
        vector<int>dp(arr.size(),-1);
        return solve(arr,0,-1,difference,dp);
    }
};