class Solution {
public:
    vector<int> dp;

    Solution() : dp(101, -1) {}
    int climbStairs(int n) {
        if(n<0){
            
            return 0;
        }
        if(n==0){
            return 1;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
       
        int ans=climbStairs(n-1)+climbStairs(n-2);
        return dp[n]=ans;

    }
};