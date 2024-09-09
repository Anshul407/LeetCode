class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        vector<int>newx=nums;
        sort(nums.begin(),nums.end());
        int x=nums[nums.size()-1];
        int y=nums[nums.size()-2];
        if(x<2*y)return -1;

        for(int i=0;i<nums.size();i++){
            if(newx[i]==x)return i;
        }
        return -1;
    }
};