class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (auto i : nums) mp[i]++;
        
        int ind = -1, maxi = INT_MIN;
        for (auto i : mp) {
            if (maxi < i.second) {
                maxi = i.second;
                ind = i.first;
            }
        }
        
        int cnt = 0;
        unordered_map<int, int> mp2;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == ind) {
                cnt++;
            }
            mp2[i] = cnt;
        }
        
        for (int i = 0; i < nums.size(); i++) {
            // Frequency condition for the first part (0 to i)
            bool freq1 = mp2[i] * 2 > (i + 1);
            // Frequency condition for the second part (i+1 to end)
            bool freq2 = (maxi - mp2[i]) * 2 > (nums.size() - i - 1);
            
            if (freq1 && freq2) {
                return i;
            }
        }

        return -1;
    }
};
