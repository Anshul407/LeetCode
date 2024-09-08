class Solution {
public:
    long long findMaximumScore(vector<int>& nums) {
        int p = 0;  
        long long ans = 0; 
        
   
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] >= nums[p]) {
                
                ans += (1LL * nums[p] * (i - p));
                p = i;  
            }
        }

       
        if (p != nums.size() - 1) {
            ans += (1LL * nums[p] * (nums.size() - 1 - p));
        }
        
        return ans;
    }
};
