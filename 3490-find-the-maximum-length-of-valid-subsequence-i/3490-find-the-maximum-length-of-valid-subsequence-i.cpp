class Solution {
public:
    vector<vector<vector<int>>>dp;
    int maximumLength(vector<int>& nums) {
        dp.resize(nums.size(),vector<vector<int>>(2,vector<int>(2,0)));
        auto x=nums[0]%2;
        dp[0][x][0]=1;
        dp[0][x][1]=1;
        int ans=0;
        for(int i=1;i<nums.size();i++){
            auto cur=nums[i]%2;
            for(int j=0;j<2;j++){
                for(int k=0;k<2;k++){
                    dp[i][j][k]=dp[i-1][j][k];
                }
            }
            if(cur){
                dp[i][cur][0]=1+dp[i-1][cur][0];
                dp[i][cur][1]=1+dp[i-1][!cur][1];
            }else{
                dp[i][cur][0]=1+dp[i-1][cur][0];
                dp[i][cur][1]=1+dp[i-1][!cur][1];
            }
            ans=max({ans,dp[i][cur][0],dp[i][cur][1]});

        }
        return ans;
    }
};