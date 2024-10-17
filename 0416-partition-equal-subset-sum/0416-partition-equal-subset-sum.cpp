class Solution {
public:
    vector<vector<int>>dp;
    int solve(vector<int>&nums,int i,int k){
        if(k<0)return 0;
        if(i>=nums.size())return k==0;
        if(dp[i][k]!=-1)return dp[i][k];
        int op1=solve(nums,i+1,k-nums[i]);
        int op2=solve(nums,i+1,k);
        return dp[i][k]=op1||op2;
        }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(auto i:nums){
            sum+=i;
        }
        
        if(sum%2!=0)return 0;
        dp.resize(nums.size(),vector<int>((sum/2)+1,-1));
        return solve(nums,0,sum/2);
    }
};