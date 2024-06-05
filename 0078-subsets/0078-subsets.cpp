class Solution {
public:
void mp(vector<int>nums,vector<int>op,vector<vector<int>>&v,int index){
    if(index>=nums.size()){
        v.push_back(op);
        return ;
    }

    //excluding the elem
    mp(nums,op,v,index+1);
    //including the element
    op.push_back(nums[index]);
    mp(nums,op,v,index+1);
    
}
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>op;
       vector<vector<int>>ans;
        mp(nums,op,ans,0);
        return ans;
    }
};