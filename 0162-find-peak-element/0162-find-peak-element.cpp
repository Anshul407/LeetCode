class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size()==1)return 0;
        if(nums[0]>nums[1])return 0;
        if(nums[nums.size()-1]>nums[nums.size()-2])return nums.size()-1;
        int n=nums.size();
        int s=0;
        int e=n-1;
        while(s<=e){
            int mid=(s+e)/2;
            int prev=(mid+n-1)%n;
            int next=(mid+1)%n;
            if(nums[mid]>nums[prev]&&nums[mid]>nums[next]){
                return mid;
            }
            else if(nums[mid]<nums[prev]){
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return -1;
    }
};