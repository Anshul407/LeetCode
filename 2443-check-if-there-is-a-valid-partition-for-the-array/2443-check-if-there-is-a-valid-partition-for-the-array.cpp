class Solution {
public:
    int dp[100001];
    int solve(vector<int>&nums,int i){
        if(i>=nums.size())return 1;
        if(dp[i]!=-1)return dp[i];
        int op1=0,op2=0,op3=0;
        if(i+1<nums.size()&&nums[i]==nums[i+1]){
            op1=max(op1,solve(nums,i+2));  
        }
        if(i+2<nums.size()&&nums[i+2]==nums[i+1]&&nums[i]==nums[i+1]){
                op2=max(op2,solve(nums,i+3));
        }
        if(i+2<nums.size()){
                if(nums[i]==nums[i+1]-1&&nums[i+1]==nums[i+2]-1)
                op3=max(op3,solve(nums,i+3));          
        }
        return dp[i]=op1||op2||op3;
    }
    bool validPartition(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return solve(nums,0);
    }
};