class Solution {
public:
    int solve(vector<int>& a, vector<int>& b, int i, vector<vector<int>>& dp, bool swapped) {
        if (i >= a.size()) return 0;

        if (dp[i][swapped] != -1) return dp[i][swapped];

        int prev_a = a[i - 1];
        int prev_b = b[i - 1];
        
        if (swapped) {
            swap(prev_a, prev_b);
        }

        int ntk = INT_MAX;
        if (prev_a < a[i] && prev_b < b[i]) {
            ntk = solve(a, b, i + 1, dp, false);
        }

        int tk = INT_MAX;
        if (prev_a < b[i] && prev_b < a[i]) {
            swap(a[i], b[i]);
            tk = 1 + solve(a, b, i + 1, dp, true);
            swap(a[i], b[i]);
        }

        return dp[i][swapped] = min(tk, ntk);
    }

    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return solve(nums1, nums2, 1, dp, false);
    }
};
