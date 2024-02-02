class Solution {
public:
   
    vector<int> searchRange(vector<int>& nums, int target) {
       vector<int>ans={-1,-1};
       int st=0;
       int end=nums.size()-1;
       int mid=-1;
       while(st<=end){
           mid=st+((end-st)/2);
           if(nums[mid]==target){end=mid-1;}
           else if(nums[mid]>target){end=mid-1;}
           else{
               st=mid+1;
           }
       }
    //    if (st < nums.size() && nums[st] == target) {
    //     ans[0] = st;
    // }
      
      if(nums[st]==target)
      ans[0]=st;
      st=0;
       end=nums.size()-1;
       while(st<=end){
           mid=st+((end-st)/2);
           if(nums[mid]==target){st=mid+1;}
           else if(nums[mid]>target){end=mid-1;}
           else{
               st=mid+1;
           }
       }
       if(nums[end]==target)
       ans[1]=end;
       return ans;
    }
};