class Solution {
public:
    int dp[101][101][101];
    int solve(vector<int>&nums,int k,int a,int b,int i){
        if(i>=nums.size())return 0;
        if(dp[i][a][b]!=-1)return dp[i][a][b];
        int ans=nums[i]+solve(nums,k,a,b,i+1);
        if(a>0){
            ans=min(ans,(nums[i]+1)/2+solve(nums,k,a-1,b,i+1));
        }
        if(b>0&&nums[i]>=k){
            ans=min(ans,(nums[i]-k)+solve(nums,k,a,b-1,i+1));
        }
        if(b>0&&a>0){
            int x=(nums[i]+1)/2;
            if(x>=k){
                ans=min(ans,x-k+solve(nums,k,a-1,b-1,i+1));
            }
        }
        if(b>0&&a>0&&nums[i]>=k){
            int x=(nums[i]-k);
            ans=min(ans,(x+1)/2+solve(nums,k,a-1,b-1,i+1));   
        }
        return dp[i][a][b]= ans;
    }

    int minArraySum(vector<int>& nums, int k, int op1, int op2) {
        memset(dp,-1,sizeof(dp));
        return solve(nums,k,op1,op2,0);
    }
};