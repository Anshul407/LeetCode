class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        set<int>s;
        for(int i=0;i<nums.size();i++){

        }
        sort(nums.begin(),nums.end());
        return nums[nums.size()-k];
    }
};