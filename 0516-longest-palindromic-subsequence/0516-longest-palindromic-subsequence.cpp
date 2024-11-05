class Solution {
public:
    int dp[1001][1001];
    int solve(string &s,int i,int j){
        if(i>j)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int op1=0,op2=0,op3=0;
        
        if(s[i]==s[j]){
            if(i!=j)
            op1=2+solve(s,i+1,j-1);
            else op1=1+solve(s,i+1,j-1);
        }
        op2=solve(s,i+1,j);
        op3=solve(s,i,j-1);
        return dp[i][j]= max({op1,op2,op3});
    }
    int longestPalindromeSubseq(string s) {
        memset(dp,-1,sizeof(dp));
        return solve(s,0,s.size()-1);
    }
};