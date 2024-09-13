class Solution {
public:
    vector<vector<int>>dp;
    int solve(vector<int>&nums,int i,int p){
        if(i>=nums.size())return 0;
        if(dp[i][p+1]!=-1)return dp[i][p+1];
        int op1=solve(nums,i+1,p);
        int op2=0;
      
        if(p==-1||nums[p]==sqrt(nums[i])){
            op2=1+solve(nums,i+1,i);
        }
        return dp[i][p+1]= max(op1,op2);
    }
    int longestSquareStreak(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        dp.resize(nums.size(),vector<int>(nums.size()+1,-1));
        
        int ans= solve(nums,0,-1);
        
        if(ans<2)return -1;
        return ans;
    }
};