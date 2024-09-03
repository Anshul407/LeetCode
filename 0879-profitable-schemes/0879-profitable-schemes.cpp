class Solution {
public:
    vector<vector<vector<int>>> dp;
    const int MOD=1e9+7;
    int solve(int n, int mini, vector<int>& gr, vector<int>& pr, int i, int cost, int profit) {
        if (cost > n) return 0;
        if (i >= gr.size()) {
            return profit >= mini ? 1 : 0;
        }
        if (dp[i][cost][min(profit, mini)] != -1) return dp[i][cost][min(profit, mini)];

        int tk = (solve(n, mini, gr, pr, i + 1, cost + gr[i], profit + pr[i]))%MOD;
        int ntk = (solve(n, mini, gr, pr, i + 1, cost, profit))%MOD;

        return dp[i][cost][min(profit, mini)] =( tk + ntk)%MOD;
    }
    
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        dp.resize(group.size(), vector<vector<int>>(n + 1, vector<int>(minProfit + 1, -1)));
        return solve(n, minProfit, group, profit, 0, 0, 0);
    }
};
