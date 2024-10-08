class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long totalPeriods = 0;
        long long currentPeriodLength = 1;

        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i] == prices[i - 1] - 1) {
                currentPeriodLength++;
            } else {
                currentPeriodLength = 1;  // Reset the period length
            }
            totalPeriods += currentPeriodLength;
        }

        return totalPeriods + 1;  
    }
};
