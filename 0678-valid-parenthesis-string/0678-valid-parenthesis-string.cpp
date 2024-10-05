class Solution {
public:
    int dp[101][201];
    int solve(string &s, int i, int op) {
        if(i==s.length())return op==0;
        if(dp[i][op]!=-1)return dp[i][op];
        int ans=0;
        if(s[i]=='*'){
            ans=max(ans,solve(s,i+1,op+1));
            ans=max(ans,solve(s,i+1,op));
            if(op)
            ans=max(ans,solve(s,i+1,op-1));
        }else {
            if(s[i]=='(')ans=solve(s,i+1,op+1);
            else if(op) ans=solve(s,i+1,op-1);
        }

        return dp[i][op]= ans;
    }

    bool checkValidString(string s) {
        memset(dp,-1,sizeof(dp));
       
        return solve(s, 0, 0);
    }
};
