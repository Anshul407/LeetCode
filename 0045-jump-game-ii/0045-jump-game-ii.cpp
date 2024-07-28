class Solution {
public:
    int solve(vector<int>& nums,int i,int n,int cnt,vector<int>&dp){
        if(i>=n-1){
           
            return 0;
        }
        if(dp[i]!=-1)return dp[i];
        int step=INT_MAX;
        for(int j=1;j<=nums[i];j++){
            int x=solve(nums,i+j,n,cnt+1,dp);
            if(x!=INT_MAX)
            step=min(step,x+1);
        }

        return dp[i]=step;
        
    }
    int jump(vector<int>& nums) {
        int cnt=0;
        int ans=INT_MAX;
        vector<int>dp(nums.size(),-1);
        return solve(nums,0,nums.size(),cnt,dp);
        return ans;
    }
};