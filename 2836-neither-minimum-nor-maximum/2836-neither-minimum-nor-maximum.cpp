class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        
        if(nums.size()<=2)return -1;
        int x=nums[0];
        int y=nums.back();
        for(int i=1;i<nums.size();i++){
            if(nums[i]!=x&&nums[i]!=y)return nums[i];
        }
        return -1;
    }
};