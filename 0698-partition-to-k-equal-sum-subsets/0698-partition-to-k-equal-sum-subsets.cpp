class Solution {
public:
    int f;
    vector<int>dp;
    int solve(vector<int>&nums,int i,int cur,int k,int mask){
        if(k==0)return mask==(1<<nums.size())-1;
        if(cur==f)return solve(nums,0,0,k-1,mask);
        if(i>=nums.size()||cur>f)return 0;
        if(dp[mask]!=-1)return dp[mask];
        for(int x=0;x<nums.size();x++){
            if((mask&(1<<x))==0&&cur+nums[x]<=f){
                int newmask=mask|(1<<x);
                if(solve(nums,x+1,cur+nums[x],k,newmask))return dp[mask]=1;
               
            }
        } 
        return dp[mask]= 0;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum=0;
        for(auto i:nums){
            sum+=i;
        }
        if(sum%k!=0)return 0;
        f=(sum/k);
        
        dp.resize((1<<nums.size())+1,-1);
        return solve(nums,0,0,k,0);
        
    }
};