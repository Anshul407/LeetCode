class Solution {
public:
   void mp(vector<int> nums,vector<int>op,set<vector<int>>&ans){
       if(nums.size()==0){
           sort(op.begin(),op.end());
           ans.insert(op);
           return ;
       }
       vector<int>op1(op);
       vector<int>op2(op);

       op2.push_back(nums[0]);
       nums.erase(nums.begin()+0);

       mp(nums,op1,ans);
       mp(nums,op2,ans);

   }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>op;
        set<vector<int>>ans;
        mp(nums,op,ans);
        vector<vector<int>>ans1;
        for(auto i:ans){
            ans1.push_back(i);
        }
        return ans1;
    }
};