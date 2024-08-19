class Solution {
public:
    int solve(string s,int i,int min,int maxi,vector<int>&dp){
        if(i>=dp.size()-1)return 1;
        int tk=0;
        if(dp[i]!=-1)return dp[i];
        for(int j=maxi;j>=min;j--){
            if(i+j<s.length()&&s[i+j]=='0'){
                tk=max(tk,solve(s,i+j,min,maxi,dp));
                if(tk)return dp[i]=1;
            }
        }

        return dp[i]=0;
    }
    bool canReach(string s, int minJump, int maxJump) {
    int n = s.length();
    vector<int> dp(n, 0);  // DP array to track reachable indices
    dp[0] = 1;  // Start from the first index

    for (int i = 1; i < n; i++) {
        if (s[i] == '0') {
            for (int j = max(i - maxJump, 0); j <= i - minJump; j++) {
                if (dp[j] == 1) {
                    dp[i] = 1;
                    break;
                }
            }
        }
    }
    
    return dp[n - 1] == 1;
}

};