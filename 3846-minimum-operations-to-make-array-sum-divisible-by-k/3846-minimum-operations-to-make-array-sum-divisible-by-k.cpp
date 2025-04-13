class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int cur=0;
        for(auto i:nums)cur+=i;
        return cur%k;
    }
};