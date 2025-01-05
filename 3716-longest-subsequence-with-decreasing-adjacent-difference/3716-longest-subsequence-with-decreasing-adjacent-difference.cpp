class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        vector<vector<int>>dp(302,vector<int>(302,0));
        for(int i=nums.size()-1;i>=0;i--){
            int cur=nums[i];
            for(int f=1;f<=300;f++){
                int curdiff=abs(cur-f);
                dp[cur][curdiff]=max(dp[cur][curdiff],dp[f][curdiff]+1);
            }
            for(int j=1;j<=300;j++){
                dp[cur][j]=max(dp[cur][j],dp[cur][j-1]);
            }
        }
        int ans=0;
        for(auto i:dp){
            for(auto v:i){
                ans=max(ans,v);
            }
        }
        return ans;
    }
};