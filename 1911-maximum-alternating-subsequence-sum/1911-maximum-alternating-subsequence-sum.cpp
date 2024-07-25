class Solution {
public:
   long long solve(vector<int>& nums,long long i,bool flag,vector<vector<long long>>&dp){
        if(i>=nums.size())return 0;
        long long tk=0,ign=0;
        if(dp[i][flag]!=-1)return dp[i][flag];
        if(!flag){
          tk=nums[i]+solve(nums,i+1,!flag,dp);
          ign=solve(nums,i+1,flag,dp);
        }else{
        
            tk=-nums[i]+solve(nums,i+1,!flag,dp);
            ign=solve(nums,i+1,flag,dp);
        }

        return dp[i][flag]= max(tk,ign);
    }
    long long maxAlternatingSum(vector<int>& nums) {
        long long i=0;
        vector<vector<long long>>dp(nums.size(),vector<long long>(2,-1));
       return  solve(nums,i,0,dp);
    }
};