class Solution {
public:
    int dp[1001][1001];
    int solve(vector<int>&nums,int i,int a,int b){
        if(i>=nums.size())return 0;
        if(dp[a+1][b+1]!=-1)return dp[a+1][b+1];
        int tk=0;
        if(a==-1){
            tk=1+solve(nums,i+1,i,b);
        }else if(b==-1){
            tk=1+solve(nums,i+1,a,i);
        }else if(nums[i]==nums[a]+nums[b]){
            tk=1+solve(nums,i+1,b,i);
        }

        int ntk=solve(nums,i+1,a,b);
        return dp[a+1][b+1]= max(tk,ntk);
    }
    int lenLongestFibSubseq(vector<int>& arr) {
        memset(dp,-1,sizeof(dp));
        int ans= solve(arr,0,-1,-1);
         for (int i = 0; i < arr.size(); ++i) {
            for (int j = i + 1; j < arr.size(); ++j) {
                ans = max(ans, solve(arr, j + 1, i, j) + 2); // We add 2 for the initial pair
            }
        }

        return ans > 2 ? ans : 0;
    }
};