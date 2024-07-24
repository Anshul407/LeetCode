class Solution {
public:
    int solve(vector<int>& nums,int i,vector<int>& dp){
        if(i>=nums.size())return 0;
        if(dp[i]!=-1)return dp[i];
        int l=nums[i]+solve(nums,i+2,dp);
        int r=solve(nums,i+1,dp);

        return dp[i]=max(l,r);
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1)return nums[0];
        if(nums.size()==2)return max(nums[0],nums[1]);
        int ans=0;
        int temp=0;
        int i=0;
        // vector<int>dp(nums.size()+1,0);
        // dp[0]=0;
        // dp[1]=nums[0];
        int x=0;
        int y=nums[0];
        for(int i=2;i<=nums.size();i++){
            int curr=max(x+nums[i-1],y);
            x=y;
            y=curr;
            ans=max(ans,curr);
        }
      

      
        return ans;
       
    }
};