class Solution {
public:
    vector<vector<int>>dp;
    int solve(vector<int>&nums,int i,int j,int p){
        if(i>=j)return 0;
        int op1=0,op2=0,op3=0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(p==-1||nums[i]+nums[i+1]==p){
            op1=1+solve(nums,i+2,j,nums[i]+nums[i+1]);
        }
        if(p==-1||nums[i]+nums[j]==p){
            op2=1+solve(nums,i+1,j-1,nums[i]+nums[j]);
        }

        if(p==-1||nums[j]+nums[j-1]==p){
            op3=1+solve(nums,i,j-2,nums[j]+nums[j-1]);
        }

        return dp[i][j]= max({op1,op2,op3});

    }

    int maxOperations(vector<int>& nums) {
        dp.resize(nums.size(),vector<int>(nums.size(),-1));
        return solve(nums,0,nums.size()-1,-1);
    }
};