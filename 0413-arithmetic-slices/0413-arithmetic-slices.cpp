class Solution {
public:
    int solve(int i,vector<int>&nums,vector<int>&dp){
        if(i>=nums.size())return 0;
       
        if(dp[i]!=-1)return dp[i];
        int tk=0;
        
       
        if(nums[i]-nums[i-1]==nums[i-1]-nums[i-2]){
        tk+=(1+solve(i+1,nums,dp));
        }
       


        return dp[i]=tk;

        
    }
    int numberOfArithmeticSlices(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        if(nums.size()<=2)return 0;
        int ans=0;
        for(int i=2;i<nums.size();i++)
        ans+= solve(i,nums,dp);
        return ans;
    }
};