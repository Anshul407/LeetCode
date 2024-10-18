class Solution {
public:
    int solve(vector<int>&nums,int i,int x,int c){
        if(i>=nums.size())return c==x;

        int op1=solve(nums,i+1,x,c|nums[i]);
        int op2=solve(nums,i+1,x,c);
        return op1+op2;
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int x=0;
        for(auto i:nums){
            x|=i;
        }
       return solve(nums,0,x,0);
    }
};