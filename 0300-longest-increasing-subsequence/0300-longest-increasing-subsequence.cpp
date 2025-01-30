class Solution {
public:
    int dp[2501][2501];
    int solve(vector<int>&nums,int i,int p){
        if(i>=nums.size())return 0;
        if(dp[i][p+1]!=-1)return dp[i][p+1];
        int ans=0;
        if(p==-1||nums[i]>nums[p]){
            ans=1+solve(nums,i+1,i);
        }
        return dp[i][p+1]=max(ans,solve(nums,i+1,p));
    }
    int lengthOfLIS(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return solve(nums,0,-1);
    }
};