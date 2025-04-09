class Solution {
public:
    int fnc(vector<int>& nums,int i,int ans)
    {
        if(i>=nums.size())
        return ans;
        int op1=0,op2=0;
        op1+=fnc(nums,i+1,(ans^nums[i]));
        op1+=fnc(nums,i+1,ans);
        return op1;
    }
    int subsetXORSum(vector<int>& nums) {
        return fnc(nums,0,0);
    }
};