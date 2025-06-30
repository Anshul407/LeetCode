class Solution {
public:
    void solve(vector<int>&nums,vector<int>&t,int state,vector<vector<int>>&ans){
        if(state==(1<<nums.size())-1){
            ans.push_back(t);
            return ;
        }

        for(int i=0;i<nums.size();i++){
            if(state&(1<<i))continue;
            int curstate=state|(1<<i);
            t.push_back(nums[i]);
            solve(nums,t,curstate,ans);
            t.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        solve(nums,temp,0,ans);
        return ans;
    }
};