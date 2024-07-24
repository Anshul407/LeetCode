class Solution {
public:
    int solve(vector<int>nums,int i,vector<int>&dp){
        if(i>=nums.size())return 0;
        if(dp[i]!=-1)return dp[i];

        int x=nums[i]+solve(nums,i+2,dp);
        int y=solve(nums,i+1,dp);
        return dp[i]=max(x,y);
        
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1)return nums[0];
        if(nums.size()==2)return max(nums[0],nums[1]);
        
        vector<int>dp(nums.size()+1,-1);
        vector<int>a(nums.begin()+2,nums.end()-1);
        vector<int>b(nums.begin()+1,nums.end());
        int ans1=nums[0]+solve(a,0,dp);
         vector<int>dp2(nums.size()+1,-1);
         int ans2=solve(b,0,dp2);

         return max(ans1,ans2);
    }
};