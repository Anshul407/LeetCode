class Solution {
public:
    int solve(vector<int>&nums,int i,int p,long long t,vector<int>&dp){
        if(i==nums.size()-1)return 0;
        int ans=INT_MIN;
        if(dp[i]!=-1)return dp[i];
        for(int j=i+1;j<nums.size();j++){
             int sol=INT_MIN;
            if(nums[j]-nums[i]<=t&&nums[j]-nums[i]>=(-1*t)){              
                 ans=max(ans,1+solve(nums,j,p+1,t,dp));  
              
            }
               
        }
        return dp[i]=ans;
    }
    int maximumJumps(vector<int>& nums, int target) {
        vector<int>dp(nums.size(),-1);
        long long t=target;
        int ans= solve(nums,0,0,t,dp);
        
        if(ans<0)return -1;
        return ans;
    }
};