class Solution {
public:
    int numDistinct(string s, string t) {
        vector<vector<long long>>dp(s.size()+1,vector<long long>(t.size()+1,0));
        for(int i=0;i<s.size();i++){
            dp[i][0]=1;
        }
       
        for(int i=1;i<=s.size();i++){
            for(int j=1;j<=t.size();j++){
                if(s[i-1]==t[j-1])
                dp[i][j]=dp[i][j]+dp[i-1][j-1];
                dp[i][j]=dp[i][j]+dp[i-1][j];
            }
        }
        return dp[s.size()][t.size()];
    }
};

