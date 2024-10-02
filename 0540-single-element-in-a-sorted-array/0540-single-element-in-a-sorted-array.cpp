class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
       int i=0,j=nums.size()-1;
       while(i<j){
            int mid=(i+j)/2;
            bool even=1;
            if((j-mid)%2==1){
                even=0;
            }
            if(nums[mid]==nums[mid+1]){
                if(even){
                    i=mid+2;
                }else j=mid-1;
            }else{
                if(even){
                    j=mid;
                }else i=mid+1;
            }
       }
       return nums[i];
    }
};