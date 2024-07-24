class Solution {
public:
    int solve(vector<int>& nums,int i,vector<int>& dp){
        if(i>=nums.size())return 0;
        if(dp[i]!=-1)return dp[i];
        int l=nums[i]+solve(nums,i+2,dp);
        int r=solve(nums,i+1,dp);

        return dp[i]=max(l,r);
    }
    int rob(vector<int>& nums) {
        int ans=0;
        int temp=0;
        int i=0;
        vector<int>dp(nums.size()+1,-1);
        return solve(nums,i,dp);
       
    }
};