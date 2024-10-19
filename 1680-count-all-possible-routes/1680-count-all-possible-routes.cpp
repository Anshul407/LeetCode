class Solution {
public:
    int mod = 1e9 + 7;
    vector<vector<int>> dp;

    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        dp = vector<vector<int>>(locations.size(), vector<int>(fuel + 1, -1));
        return helper(locations, start, finish, fuel);
    }

    int helper(vector<int>& locations, int start, int finish, int fuel) {
        if (fuel < 0) return 0;  // If fuel goes below 0, no valid route
        if (dp[start][fuel] != -1) return dp[start][fuel];  // Use memoized result
        
        int ans = (start == finish) ? 1 : 0;  // If at finish, count this as 1 valid route

        for (int i = 0; i < locations.size(); i++) {
            if (i != start) {
                int fuelCost = abs(locations[i] - locations[start]);
                if (fuel >= fuelCost) {
                    ans = (ans + helper(locations, i, finish, fuel - fuelCost)) % mod;
                }
            }
        }
        return dp[start][fuel] = ans;
    }
};
