class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        vector<int>dp(nums.size(),1);
        vector<int>count(nums.size(),1);
        dp[0]=1;
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    if(dp[i]==dp[j]+1){
                        count[i]+=count[j];
                    }
                    else if(dp[i]<dp[j]+1){
                        count[i]=count[j];
                    }
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
        }
        int maxi=0;
        for(auto i:dp){
            maxi=max(maxi,i);
        }
        int cnt=0;
       for(int i=0;i<nums.size();i++){
            if(dp[i]==maxi)cnt+=count[i];
       }
       return cnt;
    }
};