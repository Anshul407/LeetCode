class Solution {
public:
    int dp[101][201];
    int solve(string s,int i,int c){
        if(i>=s.size())return c==0;
        if(dp[i][c]!=-1)return dp[i][c];
        int ans=0;
        if(s[i]=='*'){
            ans=max(ans,solve(s,i+1,c));
            ans=max(ans,solve(s,i+1,c+1));
            if(c)ans=max(ans,solve(s,i+1,c-1));
        }
        else {
            if(s[i]=='(')ans=max(ans,solve(s,i+1,c+1));
            else if(c) ans=max(ans,solve(s,i+1,c-1));
        }

        return dp[i][c]=ans;
        
    }
    bool checkValidString(string s) {
        memset(dp,-1,sizeof(dp));
       return solve(s,0,0);
    }
};