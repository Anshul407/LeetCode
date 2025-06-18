class Solution {
public:
    void solve(vector<int>&nums,vector<int>&t,vector<vector<int>>&ans,int state){
        if(state==(1<<nums.size())-1){
            ans.push_back(t);
            return ;
        }
        for(int i=0;i<nums.size();i++){
 
            int newstate=state|(1<<i);
            int curstate=state&(1<<i);
            if(i!=0&&nums[i]==nums[i-1]&&!(state&(1<<(i-1))))continue;

            if(curstate==0){
               
                t.push_back(nums[i]);
                solve(nums,t,ans,newstate);
                t.pop_back();
            }
        }

    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>t;
       vector<int>vis(nums.size(),0);
        vector<vector<int>>ans;
        solve(nums,t,ans,0);
        return ans;
    }
};