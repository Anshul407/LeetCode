class Solution {
public:
    int dp[50001];
    
    int solve(vector<int>& values, int j, int maxSoFar) {
        if (j >= values.size()) return 0;
        if (dp[j] != -1) return dp[j];

        int maxScore = maxSoFar + values[j] - j;
        maxSoFar = max(maxSoFar, values[j] + j);

        return dp[j] = max(maxScore, solve(values, j + 1, maxSoFar));
    }

    int maxScoreSightseeingPair(vector<int>& values) {
        memset(dp, -1, sizeof(dp));
        return solve(values, 1, values[0]);
    }
};
