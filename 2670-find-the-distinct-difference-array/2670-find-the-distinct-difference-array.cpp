  class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        int ts = nums.size(); // Total size of the nums array
        vector<int> ans;      // Answer vector to store the result

        // Step 1: Create a map to count the occurrences of each element in nums
        map<int, int> m1;
        for (const auto& i : nums) {
            m1[i]++;
        }

        // Step 2: Create a vector to store unique elements from nums
        vector<int> uniq;
        for (const auto& i : m1) {
            uniq.push_back(i.first);
        }

        // Step 3: Iterate through nums to calculate prefix and suffix unique counts
        for (int i = 0; i < ts; i++) {
            map<int, int> prefix_map;
            map<int, int> suffix_map;

            // Calculate unique count in the prefix
            for (int j = 0; j <= i; j++) {
                prefix_map[nums[j]]++;
            }
            int ps = prefix_map.size();

            // Calculate unique count in the suffix
            for (int j = i + 1; j < ts; j++) {
                suffix_map[nums[j]]++;
            }
            int ss = suffix_map.size();

            // Difference between prefix and suffix unique counts
            int as = ps - ss;
            ans.push_back(as);
        }

        return ans;
    }
};
