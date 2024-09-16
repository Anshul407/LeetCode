class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        for(auto &i:nums){
            if(k<=0)break;
            if(i<0){
                i*=-1;
                k--;
            }
        }
        sort(nums.begin(),nums.end());
        if(k%2==1){
            nums[0]*=-1;
        }
        int sum=0;
        for(auto i:nums)sum+=i;
        return sum;
    }
};