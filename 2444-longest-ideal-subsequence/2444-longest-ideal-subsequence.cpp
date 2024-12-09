class Solution {
public:
    int solve(string &s, int i, int k, int p, vector<vector<int>> &dp) {
        if (i >= s.size()) return 0;
        
        int prevIndex = (p == -1 ? 26 : s[p] - 'a');
        if (dp[i][prevIndex] != -1) return dp[i][prevIndex];

        // Include current character if valid
        int op1 = 0, op2 = 0;
        if (p == -1 || abs(s[p] - s[i]) <= k)
            op1 = 1 + solve(s, i + 1, k, i, dp);

        // Skip current character
        op2 = solve(s, i + 1, k, p, dp);

        return dp[i][prevIndex] = max(op1, op2);
    }

    int longestIdealString(string s, int k) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(27, -1));
        return solve(s, 0, k, -1, dp);
    }
};
