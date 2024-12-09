class Solution {
public:
    int longestIdealString(string s, int k) {
        vector<int>dp(26,0);
        int ans=0;
        for(int i=0;i<s.length();i++){
            int indx=s[i]-'a';
            int rightrange=min(25,indx+k);
            int leftrange=max(0,indx-k);
            int maxi=0;
            for(int j=leftrange;j<=rightrange;j++){
                maxi=max(maxi,dp[j]);
            }
            dp[indx]=max(dp[indx],maxi+1);
            ans=max(ans,dp[indx]);
        }
        
        return ans;
    }
};