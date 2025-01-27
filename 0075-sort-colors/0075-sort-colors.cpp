class Solution {
public:
    void sortColors(vector<int>& nums) {
        int z=0,o=0,t=nums.size()-1;
        while(o<=t){
            if(nums[o]==0){
                swap(nums[o],nums[z]);
                o++;z++;
            }else if(nums[o]==1)o++;
            else{
                swap(nums[o],nums[t]);
                o++;
                t--;
            }
        }
    }
};