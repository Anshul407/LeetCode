class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long maxi=-1,mini=-1,ci=-1;
        long long ans=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>maxK||nums[i]<minK)ci=i;
            if(nums[i]==minK)mini=i;
            if(nums[i]==maxK)maxi=i;
            auto cur=min(mini,maxi);
            auto temp=cur-ci;
            if(temp>=0)ans+=temp;
        }return ans;
    }
};