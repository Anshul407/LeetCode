class Solution {
public:
    int dp[100001][2];
    bool issame(int p, int q) {
        if (p == -1) return true;
        return (p % 2 == q % 2);
    }
    int solve(vector<int>&nums,int x,int i,int p){
        if(i>=nums.size())return 0;
        int parity = (p == -1) ? 0 : (p % 2);  // Convert to 0 or 1 for indexing
        if (dp[i][parity] != -1) return dp[i][parity];
        int tk=0;
        if(issame(p,nums[i])){
            tk=nums[i]+solve(nums,x,i+1,nums[i]);
        }else{
            tk=-x+nums[i]+solve(nums,x,i+1,nums[i]);
        }
        int ntk=solve(nums,x,i+1,p);

        return dp[i][parity]= max(tk,ntk);
    }
    long long maxScore(vector<int>& nums, int x) {
        memset(dp,-1,sizeof(dp));
        return nums[0]+ solve(nums,x,1,nums[0]);
    }
};