class Solution {
public:
    bool ff(vector<vector<vector<int>>> &dp, int i, int j, int n, int m, int s, vector<vector<char>> &a)
    {
        if(i == n || j == m || s < 0) return false;
        if(i == n - 1 && j == m - 1) 
        {
            int sum = (a[i][j] == '(' ? s + 1 : s - 1);
            return (sum == 0);
        }
        if(dp[i][j][s] != -1) return dp[i][j][s];
        // Go Down
        if(ff(dp, i + 1, j, n, m, ((a[i][j] == '(') ? s + 1 : s - 1), a)) return dp[i][j][s] = true;
        // Go Right
        if(ff(dp, i, j + 1, n, m, ((a[i][j] == '(') ? s + 1 : s - 1), a)) return dp[i][j][s] = true;
        return dp[i][j][s] = false;
    }
    bool hasValidPath(vector<vector<char>>& a) 
    {
        int n = a.size(), m = a[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (m, vector<int> (n + m + 2, -1)));
        return ff(dp, 0, 0, n, m, 0, a);
    }
};