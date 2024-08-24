class Solution {
public:
    int dp[100000];
    int solve(int i, vector<int>& nums) {
        if (i >= nums.size())
            return 0;
        if(dp[i]!=-1)return dp[i];
                int tk = 0;
        for (int j = i; j < nums.size(); j++) {
            int value = nums[j];
            int jj = j;

            int sum = 0;
            while (jj < nums.size() && nums[jj] == value) {
                sum += nums[jj];
                jj++;
            }

            while (jj < nums.size() && nums[jj] == value + 1) {
                jj++;
            }

            tk = max(tk, sum + solve(jj, nums));
        }

        return dp[i]=tk;
    }

    int deleteAndEarn(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        sort(nums.begin(), nums.end());
        return solve(0, nums);
    }
};
