class Solution {
public:
    map<pair<int,int>,vector<int>>mp;
    vector<int> solve(vector<int>& nums, int i, int p) {
        if (i >= nums.size())
            return {};
        vector<int> op1;
        if (p == -1 || nums[p] % nums[i] == 0 || nums[i] % nums[p] == 0) {
            op1.push_back(nums[i]);

            auto x = solve(nums, i + 1, i);

            
            op1.insert(op1.end(), x.begin(), x.end());
        }

        auto op2 = solve(nums, i + 1, p);
        if (op1.size() > op2.size())
            return op1;
        return op2;
    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        return solve(nums, 0, -1);
    }
};