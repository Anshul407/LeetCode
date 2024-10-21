class Solution {
public:
    int target;
    bool isValid(vector<int>& current,int val){
        for(auto it:current)
        {
            if(abs(it-val)==target)
            return false;
        }
        return true;
    }
    int solve(int index,vector<int>& nums,vector<int>& curr)
    {
        if(index==nums.size())
        {
            return 1;
        }
        int op1=solve(index+1,nums,curr);
        int op2=0;
        if(isValid(curr,nums[index]))
        {
        curr.push_back(nums[index]);
        op2=solve(index+1,nums,curr);
        curr.pop_back();
        }
        return op1+op2;
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        vector<int> c;
        target=k;
        return solve(0,nums,c)-1;
    }
};