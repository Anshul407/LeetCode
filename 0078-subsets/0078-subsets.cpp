class Solution {
public:
    void solve(vector<int>&nums,vector<int>&temp,vector<vector<int>>&ans,int i){
        if(i>=nums.size()){
            ans.push_back(temp);
            return ;
        }
        solve(nums,temp,ans,i+1);
        temp.push_back(nums[i]);
        solve(nums,temp,ans,i+1);
        temp.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>temp;
        vector<vector<int>>ans;
        solve(nums,temp,ans,0);
        return ans;
    }
};