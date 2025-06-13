class Solution {
public:
    bool can(vector<int>&nums,int p,int m){
        int f=0;
        for(int i=1;i<nums.size();i++){
            auto cur=abs(nums[i]-nums[i-1]);
            if(cur<=m)p--,i++;
            if(cur==m)f=1;
        }
        return p<=0;
    }
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(),nums.end());
        long long i=0,j=1e10;
        int ans=-1;
        while(i<=j){
            auto mid=(i+j)/2;
            if(can(nums,p,mid)){
                ans=mid;
                j=mid-1;
            }else i=mid+1;
        }
        return ans;
    }
};