class Solution {
public:
    int val;
    vector<int>dp;
    bool solve(vector<int>& nums,int sum,int bitmask,int k)
    {
        if(sum==0&&k==1)
        return true;
        if(sum<0)return false;
        if(dp[bitmask]!=-1)return dp[bitmask];
        if(sum==0)
        {
            k--;
            sum=val;
        }
        int ans=false;
        for(int i=0;i<nums.size();i++)
        {
            if((bitmask&(1<<i))==false)
            ans=ans||solve(nums,sum-nums[i],bitmask|(1<<i),k);
        }
        return dp[bitmask]= ans;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        dp.resize(1<<nums.size(),-1);
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {sum+=nums[i];}
        if(sum%k!=0)
        return false;
        sum/=k;
        for(auto it:nums)
        if(it>sum)
        return false;
        val=sum;
        return solve(nums,sum,0,k);

    }
};