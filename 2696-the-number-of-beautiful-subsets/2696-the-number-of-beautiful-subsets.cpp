class Solution {
public:
    int chck(int s,vector<int>&a,int k){
        for(auto &i:a){
            if(abs(i-s)==k)return 0;
        }
        return 1;
    }
    int solve(vector<int>&nums,int i,int &k,vector<int>&a){
        if(i>=nums.size()){
            return a.size()>0;
        }

        int op1=0,op2=0;
        op2=solve(nums,i+1,k,a);
        if(chck(nums[i],a,k)){
            a.push_back(nums[i]);
            op1=solve(nums,i+1,k,a);
            a.pop_back();
        }
        return op1+op2;   
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        vector<int>a;
        return solve(nums,0,k,a);
    }
};