class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_element = INT_MIN;
        int n = nums.size();
        int sum = 0;
        if (n == 1) {
            return nums[0];
        }
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            if (sum > max_element) {
                max_element = sum;
            }
            if (sum < 0) {
                sum = 0;
            }
        }
        
        return max_element;
    }
};