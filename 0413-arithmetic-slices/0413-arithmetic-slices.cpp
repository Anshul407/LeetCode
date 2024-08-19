class Solution {
public:
    int solve(int i,vector<int>&nums,vector<int>&dp){
        if(i>=nums.size())return 0;
       
        if(dp[i]!=-1)return dp[i];
        int tk=0;
        int ntk=0;
        for(int j=i;j<nums.size();j++){
           if(nums[j]-nums[j-1]==nums[j-1]-nums[j-2]){
            tk+=(1+solve(j+1,nums,dp));
        }
        }
        // ntk=solve(i+1,nums,dp);

        return dp[i]=tk+ntk;

        
    }
    int numberOfArithmeticSlices(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        if(nums.size()<=2)return 0;
        return solve(2,nums,dp);
    }
};