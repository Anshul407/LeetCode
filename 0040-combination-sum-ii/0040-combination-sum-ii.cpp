class Solution {
public:
    void solve(vector<int>&nums, vector<int> &op, vector<vector<int>>& st, int i,
               int k) {
      if(k==0){
          st.push_back(op);
          return;
      }
      if(k<0){
          return ;
      }
      for(int j=i;j<nums.size();j++){
          if(k<nums[j])break;
          if(j>i&&nums[j]==nums[j-1])continue;
          op.push_back(nums[j]);
          solve(nums,op,st,j+1,k-nums[j]);
          op.pop_back();
      }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        sort(candidates.begin(), candidates.end());

        vector<int> op;
        vector<vector<int>> st;
        int i = 0;
        solve(candidates, op, st, i, target);
       
        return st;
    }
};