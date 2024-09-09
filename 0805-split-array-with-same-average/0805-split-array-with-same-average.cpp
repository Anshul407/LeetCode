class Solution {
public:
    unordered_map<string,bool> mp;
    
    bool solve(vector<int>& nums, int i, int cnt, long long sum, long long csum) {
       
        if (i >= nums.size()) {
            if (cnt == 0 || cnt == nums.size()) return false;  
            return csum * (nums.size() - cnt) == (sum - csum) * cnt;  // Cross-multiplication to avoid floating-point issues
        }

        
        string key = to_string(i) + " " + to_string(cnt) + " " + to_string(csum);
        if (mp.find(key) != mp.end()) return mp[key];  
        
        bool op1 = solve(nums, i + 1, cnt + 1, sum, csum + nums[i]);
        if (op1) return mp[key] = true;  
        bool op2 = solve(nums, i + 1, cnt, sum, csum);
        
        return mp[key] = op1 || op2;  
    }

    bool splitArraySameAverage(vector<int>& nums) {
        long long sum = 0;
        int n = nums.size();
        
        for (auto i : nums) sum += i;

        
        bool possible = false;
        for (int cnt = 1; cnt < n; ++cnt) {
            if ((sum * cnt) % n == 0) {
                possible = true;
                break;
            }
        }
        if (!possible) return false;  
        return solve(nums, 0, 0, sum, 0);
    }
};
