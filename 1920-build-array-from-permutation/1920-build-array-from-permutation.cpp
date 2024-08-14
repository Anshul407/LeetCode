class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        vector<int>ans(nums.size(),0);
        int j=0;
        for(auto i:nums){
            ans[j]=nums[i];
            j++;
        }
        return ans;
    }
};