class Solution {
public:
void bs(vector<int>&nums,int s,int l,int&ans,int k ){
    while(s<=l){
        int mid=(s+l)/2;
        if(nums[mid]==k){
            ans=mid;
            break;
        }
        else if(nums[mid]>k){
            l=mid-1;
        }
        else{
            s=mid+1;
        }
    }
    return ;
}
    int search(vector<int>& nums, int target) {
        int index=0;
        int s=0,l=nums.size()-1;
        while(s<l){
            int mid=(s+l)/2;
            if(nums[mid]>nums[0])s=mid+1;
            else{
                l=mid;
            }
        }
        index=s;
        int ans=-1;
        bs(nums,0,index,ans,target);
        if(ans!=-1)return ans;
        bs(nums,index,nums.size()-1,ans,target);
        return ans;
    }
};