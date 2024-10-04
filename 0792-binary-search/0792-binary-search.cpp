class Solution {
public:
    int solve(vector<int>&nums,int i,int j,int k){
        if(i>j)return -1;
        else{
            int mid=(i+j)/2;
            if(nums[mid]==k)return mid;
            else if(nums[mid]>k)return solve(nums,i,mid-1,k);
            else return solve(nums,mid+1,j,k);
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
         return solve(nums,0,nums.size()-1,target);
    }
};