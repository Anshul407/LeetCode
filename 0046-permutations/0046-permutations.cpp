class Solution {
public:
    void mp(vector<int>&nums,int i,vector<vector<int>>&v){
        if(i==nums.size()-1){
            v.push_back(nums);
            return ;
        }
        for(int j=i;j<nums.size();j++){
            swap(nums[i],nums[j]);
            mp(nums, i+1, v);
            swap(nums[i],nums[j]);
        }
       
       
    }
    vector<vector<int>> permute(vector<int>& nums) {
      
        vector<vector<int>>ans;
        mp(nums,0,ans);
        return ans;
    }
};