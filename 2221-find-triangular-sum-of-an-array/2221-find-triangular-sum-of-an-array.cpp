class Solution {
public:
    int triangularSum(vector<int>& nums) {
        if(nums.size()==1)return nums[0];
        vector<int>x(nums.size()-1,0);
        for(int i=0;i<nums.size()-1;i++){
            x[i]=(nums[i]+nums[i+1])%10;
        }
        return triangularSum(x);


    }
};