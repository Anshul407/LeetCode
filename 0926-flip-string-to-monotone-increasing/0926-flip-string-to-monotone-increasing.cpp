class Solution {
public:
   
    int minFlipsMonoIncr(string s) {
        vector<vector<int>>dp(s.length()+1,vector<int>(2,0));
    
       
        int zero=0,one=0;
        for(int i=1;i<=s.length();i++){
            if(s[i-1]=='1')one++;
            if(s[i-1]=='0'){
                dp[i][0]=min(1+dp[i-1][0],one);
            }else {
                dp[i][0]=dp[i-1][0];
            }
        }

        return min(dp[s.length()][0],one);
       
    }
};