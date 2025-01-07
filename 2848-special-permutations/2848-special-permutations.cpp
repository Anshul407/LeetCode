class Solution {
public:
    const int mod=1e9+7;
    vector<vector<int>>dp;
    int solve(vector<int>&nums,int state,int p){
        if (state == (1 << nums.size()) - 1) return 1;
        if(dp[p+1][state]!=-1)return dp[p+1][state];
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(state&(1<<i))continue;
            int curstate=state|(1<<i);
            if(p==-1){
                ans=(ans+solve(nums,curstate,i))%mod;
            }else if(nums[p]%nums[i]==0||nums[i]%nums[p]==0){
                ans=(ans+solve(nums,curstate,i))%mod;
            }

        }
        return dp[p+1][state]= ans%mod;
    }
    int specialPerm(vector<int>& nums) {
        dp.resize(nums.size()+1,vector<int>(1<<nums.size(),-1));
        return solve(nums,0,-1);
    }
};