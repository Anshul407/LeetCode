class Solution {
public:
    int dp[100001];  // DP array to store the maximum cost up to each index
    unordered_map<char, int> mp;  // Map to store custom character values

    int solve(string &s, int i) {
        if (i >= s.length()) return 0;
        if (dp[i] != -1) return dp[i];

        int maxCost = 0;  // To store the maximum cost for the substring starting at index i
        int curCost = 0;  // To store the current substring cost

        for (int j = i; j < s.length(); j++) {
            int temp = (mp.find(s[j]) != mp.end()) ? mp[s[j]] : s[j] - 'a' + 1;
            curCost += temp;
            maxCost = max(maxCost, curCost);  // Update maxCost with the maximum of current substring cost
        }

        // Instead of making recursive calls inside the loop, we make only one call after
        // accumulating the cost of the entire substring starting at index i.
        maxCost = max(maxCost, solve(s, i + 1));

        return dp[i] = maxCost;  // Store the result in the DP array and return it
    }

    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        memset(dp, -1, sizeof(dp));  // Initialize the DP array with -1
        
        // Populate the map with the custom values for specific characters
        for (int j = 0; j < chars.length(); j++) {
            mp[chars[j]] = vals[j];
        }

        return solve(s, 0);  // Start solving from index 0
    }
};
