class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i=0,j=0,k=nums.size()-1;
        while(j<nums.size()){
            if(nums[j]==0){
                swap(nums[i],nums[j]);
                i++;
                j++;
            }
            else if(nums[j]==1){
                j++;
            }
            else if(j<=k){
                swap(nums[j],nums[k]);
                k--;  
            }else j++;
        }
    }
};