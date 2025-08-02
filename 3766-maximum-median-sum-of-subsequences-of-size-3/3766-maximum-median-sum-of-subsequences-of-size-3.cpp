class Solution {
public:
    long long maximumMedianSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        long long ans=0;
        int i=0,j=nums.size()-1;
        while(i<j-1){
            i++;
            j--;
            ans+=(long long)nums[j];
            j--;
        }
        return ans;

    }
};