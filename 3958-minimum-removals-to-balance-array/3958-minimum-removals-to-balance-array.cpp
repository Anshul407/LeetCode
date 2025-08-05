class Solution {
public:
    int solve(vector<int>&nums,long long cur){
        int i=0,j=nums.size()-1;
        int ans=-1;
        while(i<=j){
            auto mid=(i+j)/2;
            if(nums[mid]>cur){
                ans=mid;
                j=mid-1;
            }else i=mid+1;
        }
        if(ans==-1)return 0;
        return nums.size()-ans;
    }
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        long long ans=INT_MAX;
        for(int i=0;i<nums.size();i++){
            long long cur=i;
            long long x=solve(nums,(long long)nums[i]*k);
            cout<<x<<" ";
            ans=min(ans,cur+x);
        }return ans;
      
    }
};