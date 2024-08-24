class Solution {
public:
    int dp[100000];
    int solve(vector<int>&nums,int j){
        if(j>=nums.size())return 0;
        int maxi=0;
        if(dp[j]!=-1)return dp[j];
        for(int i=j+1;i<nums.size();i++){
            int cur=nums[i]+nums[j]+j-i;
            maxi=max(maxi,cur);
        }
       return dp[j]= max(maxi, solve(nums,j+1));

        
    }
    int maxScoreSightseeingPair(vector<int>& values) {
        memset(dp,-1,sizeof(dp));
        return solve(values,0);
    }
};