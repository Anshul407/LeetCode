class Solution {
public:
    int dp[10001];
    int solve(vector<int>&nums,int i){
        if(i>=nums.size())return 1;
        if(nums[i]==0)return i>=nums.size()-1;
        if(dp[i]!=-1)return dp[i];
        for(int k=1;k<=nums[i];k++){
            if(solve(nums,i+k))return dp[i]=1;
        }
        return dp[i]= 0;
    }
    bool canJump(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return solve(nums,0);
    }
};