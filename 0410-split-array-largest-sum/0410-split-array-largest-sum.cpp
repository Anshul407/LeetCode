class Solution {
public:
    bool check(int m,vector<int>&nums,int k){
        int cur=0;
        int s=1;
        for(int i=0;i<nums.size();i++){
            if(cur+nums[i]<=m)cur+=nums[i];
            else {
                s++;
                if(nums[i]>m||s>k)return 0;
                cur=nums[i];
            }
        }return 1;  
    }
    int splitArray(vector<int>& nums, int k) {
        
        int i=0,j=0;
        int ans=-1;
        for(auto i:nums)j+=i;
        while(i<=j){
            auto mid=(i+j)/2;
            if(check(mid,nums,k)){
                ans=mid;
                j=mid-1;
            }else i=mid+1;
        }return ans;
    }
};