class Solution {
public:
    int dp[1001][1001][3];
    int solve(vector<int>&nums,int i,int p,int flag){
        if(i>=nums.size())return 0;
        int op1=0,op2=0;
        if(dp[i][p+1][flag+1]!=-1)return dp[i][p+1][flag+1];
        if(p==-1){
            op1=1+solve(nums,i+1,i,-1);
        }else if(flag==-1){
            int newflag=(nums[i]-nums[p])>0;
            if(nums[i]-nums[p]!=0)
            op1=1+solve(nums,i+1,i,newflag);
        }else if(((nums[i]-nums[p])>0)!=flag){
            if(nums[i]-nums[p]!=0)
            op1=1+solve(nums,i+1,i,(nums[i]-nums[p])>0);
        }
        op2=solve(nums,i+1,p,flag);
        return dp[i][p+1][flag+1]=max(op1,op2);
    }
    int wiggleMaxLength(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return solve(nums,0,-1,-1);
    }
};