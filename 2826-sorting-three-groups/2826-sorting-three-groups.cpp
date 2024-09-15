class Solution {
public:
    vector<vector<int>>dp;
    int solve(vector<int>&nums,int i,int cur){
        if(i==nums.size())return 0;
        if(dp[i][cur]!=-1)return dp[i][cur];
        int op1=INT_MAX,op2=INT_MAX,op3=INT_MAX;
        if(nums[i]==cur){
            op1=solve(nums,i+1,cur);
            if(cur<2)
            op2=solve(nums,i+1,cur+1);   
        }
        else if(nums[i]<cur){
            op1=1+solve(nums,i+1,cur);
        }else if(nums[i]>cur){
            op1=1+solve(nums,i+1,cur);
            op2=solve(nums,i+1,nums[i]);
        }
        return dp[i][cur]= min(op1,op2);
    }
    int minimumOperations(vector<int>& nums) {
        dp.resize(nums.size(),vector<int>(4,-1));
        return solve(nums,0,0);
    }
};