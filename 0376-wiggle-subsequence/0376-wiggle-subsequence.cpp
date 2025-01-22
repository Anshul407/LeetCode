class Solution {
public:
    int dp[1001][1002][3];
    int solve(vector<int>&nums,int i,int j,int f){
        if(i>=nums.size())return 0;
        if(dp[i][j+1][f+1]!=-1)return dp[i][j+1][f+1];
        int op1=0;
        if(j==-1){
            op1=1+solve(nums,i+1,i,-1);
        }else if(f==-1){
            if(nums[i]-nums[j]!=0)
            op1=1+solve(nums,i+1,i,nums[i]-nums[j]>0?1:0);
        }else {
            if(f==1&&nums[i]-nums[j]<0){
                op1=1+solve(nums,i+1,i,0);
            }else if(f==0&&nums[i]-nums[j]>0)op1=1+solve(nums,i+1,i,1);
        }
        int op2=solve(nums,i+1,j,f);
        return dp[i][j+1][f+1]=max(op1,op2);
    }
    int wiggleMaxLength(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return solve(nums,0,-1,-1);
    }
};