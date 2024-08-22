class Solution {
public:
    int solve(string s,int i,map<string,int>&mp,vector<int>&dp){
        if(i>=s.length())return 1;
        string x="";
        if(dp[i]!=-1)return dp[i];
        int ans=0;
        for(int j=i;j<s.length();j++){
            x+=s[j];
            if(mp[x]){
                ans=max(ans,solve(s,j+1,mp,dp));
                if(ans)return dp[i]=1;
            }
        }
        return dp[i]=0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int>dp(s.length(),-1);
        map<string,int>mp;
        for(auto i:wordDict){
            mp[i]++;
        }
        return solve(s,0,mp,dp);
    }
};