class Solution {
public:
    int dp[1001][1001];
    int solve(string &s,int i,int k,int cur,int n){
        if(i>=s.size())return 0;
        if(dp[i][n]!=-1)return dp[i][n];
        int op1=solve(s,i+1,k,cur,n);
        int op2=0;
        // long long next=cur+((s[i]-'0')*pow(2,n));
        if(cur+((s[i]-'0')*pow(2,n))<=k){
            op2=1+solve(s,i+1,k,cur+((s[i]-'0')*pow(2,n)),n+1);
        }
        return dp[i][n]= max(op1,op2);
    }
    int longestSubsequence(string s, int k) {
        reverse(s.begin(),s.end());
        memset(dp,-1,sizeof(dp));
        return solve(s,0,k,0,0);
    }
};