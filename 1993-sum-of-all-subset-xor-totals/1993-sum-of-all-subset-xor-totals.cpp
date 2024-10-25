class Solution {
public:
    int solve(vector<int>&num,int i,int cur){
        if(i>=num.size())return cur;

        int op=0;
        op+=solve(num,i+1,cur^num[i]);
        op+=solve(num,i+1,cur);

        return op;
    }
    int subsetXORSum(vector<int>& nums) {
        return solve(nums,0,0);
    }
};