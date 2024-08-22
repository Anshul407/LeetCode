class Solution {
public:
    vector<vector<int>> ans;

    void solve(vector<int>& nums, int i, vector<int>& temp) {
        if (temp.size() > 1) {
            ans.push_back(temp);
        }
        
        unordered_set<int> used;
        for (int j = i; j < nums.size(); j++) {
            if ((temp.empty() || nums[j] >= temp.back()) && used.find(nums[j]) == used.end()) {
                used.insert(nums[j]);
                temp.push_back(nums[j]);
                solve(nums, j + 1, temp);
                temp.pop_back();  
            }
        }
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> temp;
        solve(nums, 0, temp);
        return ans;
    }
};
