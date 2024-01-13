class Solution {
public:
void mp(vector<int>nums,vector<int>op,vector<vector<int>>&v){
    if(nums.size()==0){
        v.push_back(op);
        return ;
    }
    vector<int>op1(op);
    vector<int>op2(op);
    op2.push_back(nums[0]);
    nums.erase(nums.begin()+0);
    mp(nums,op1,v);
    mp(nums,op2,v);
}
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>op;
       vector<vector<int>>ans;
        mp(nums,op,ans);
        return ans;
    }
};