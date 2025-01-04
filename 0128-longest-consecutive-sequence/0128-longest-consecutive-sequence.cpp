class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
       map<int,int>dp;
       int ans=0;
       for(int i=0;i<nums.size();i++){
           
            dp[nums[i]]=dp[nums[i]-1]+1;
            ans=max(ans,dp[nums[i]]);
       }
       return ans;

    }
   
};