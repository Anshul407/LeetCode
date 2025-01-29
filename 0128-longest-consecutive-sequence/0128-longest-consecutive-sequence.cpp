class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int,int>dp;
        int ans=0;
        sort(nums.begin(),nums.end());
        for(auto i:nums){
            dp[i]=dp[i-1]+1;
            ans=max(ans,dp[i]);
        }return ans;
    }
};