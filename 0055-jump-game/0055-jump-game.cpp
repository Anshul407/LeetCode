class Solution {
public:
    int solve(vector<int>&nums,int i,vector<int>&dp){
        if(i>=nums.size()-1)return 1;
        if(dp[i]!=-1)return dp[i];
        int st=0;
        int j=nums[i];
        if(j!=0)
        for(int x=1;x<=j;x++){
            st=max(st,solve(nums,i+x,dp));
            if(st)return dp[i]=st;
        }

        return dp[i]=st;
    }
    bool canJump(vector<int>& nums) {
        if(nums.size()==1)return 1;
       vector<int>dp(nums.size(),-1);
       return solve(nums,0,dp);
    }
};