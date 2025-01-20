class Solution {
public:
    int dp[20001];
    int solve(vector<int>&nums,int i){
        if(i>=nums.size())return 0;
        if(dp[i]!=-1)return dp[i];
        int op2=solve(nums,i+1);
        int cur=nums[i];
        int j=i;
        int tot=0;
        while(j<nums.size()&&nums[j]==cur){
            tot+=nums[j];
            j++;
        }
        while(j<nums.size()&&nums[j]==cur+1){
            j++;
        }
        int op1=tot+solve(nums,j);
        return dp[i]= max(op1,op2);

    }
    int deleteAndEarn(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        sort(nums.begin(),nums.end());
        return solve(nums,0);
    }
};