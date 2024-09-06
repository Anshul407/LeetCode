class Solution {
public:
    const int mod=1e9+7;
    vector<vector<int>>dp;
    int max_position;
    int solve(int st,int end,int n){
       
        if(n==0)return st==end;
        if(dp[st][n]!=-1)return dp[st][n];
        int op1=solve(st+1,end,n-1);
        int op2=solve(st-1,end,n-1);
        return dp[st][n]= (op1+op2)%mod;
    }
    int numberOfWays(int startPos, int endPos, int k) {
        max_position = 2 * k + startPos;
        dp.resize(max_position + 1, vector<int>(k + 1, -1));
        return solve(startPos+k,endPos+k,k);
    }
};