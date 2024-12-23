class Solution {
public:
    int solve(vector<int>nums,int i,int c,int t,vector<vector<int>>&dp){
        if(c==t)return 1;
        if(c>t)return 0;
        if(i>=nums.size())return 0;
        if(dp[i][c]!=-1)return dp[i][c];
        int ans=0;
        for(int j=0;j<nums.size();j++){
            ans+=solve(nums,j,c+nums[j],t,dp);
        }
        

        return dp[i][c]=ans;
    }
    int combinationSum4(vector<int>& nums, int target) {
        vector<vector<int>>dp(nums.size(),vector<int>(target+1,-1));
        int ans=solve(nums,0,0,target,dp);

      
        return ans;
    }
};