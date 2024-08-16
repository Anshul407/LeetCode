class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int o=0,e=0;
       while(o<nums.size()&&e<nums.size()){
            if(nums[e]%2==0){e++;
            continue;}
            if(nums[e]%2!=0){
                o=e;
                while(o<nums.size()&&nums[o]%2!=0)o++;
                if(o<nums.size())
                swap(nums[o],nums[e]);
            }
       }
       return nums;

        
    }
};