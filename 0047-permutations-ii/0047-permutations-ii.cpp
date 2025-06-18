class Solution {
public:
    void solve(vector<int>&nums,vector<int>&t,vector<vector<int>>&ans,vector<int>&vis){
        if(t.size()==nums.size()){
            ans.push_back(t);
            return ;
        }
        for(int i=0;i<nums.size();i++){
            if(i!=0&&nums[i]==nums[i-1]&&!vis[i-1])continue;
            if(vis[i]==0){
                vis[i]=1;
                t.push_back(nums[i]);
                solve(nums,t,ans,vis);
                vis[i]=0;
                t.pop_back();
            }
        }

    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>t;
       vector<int>vis(nums.size(),0);
        vector<vector<int>>ans;
        solve(nums,t,ans,vis);
        return ans;
    }
};