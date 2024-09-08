class Solution {
public:
    vector<vector<int>>dp;
    int solve(vector<int>&a,vector<int>&b,int i,int j){
        if(i>=a.size()||j>=b.size())return INT_MIN;
        if(dp[i][j]!=-1)return dp[i][j];
        int op1=a[i]*b[j]+max(0,solve(a,b,i+1,j+1));
        int op2=solve(a,b,i+1,j);
        int op3=solve(a,b,i,j+1);

        return dp[i][j]= max({op1,op2,op3});
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        dp.resize(nums1.size(),vector<int>(nums2.size(),-1));
       return solve(nums1,nums2,0,0);
    }
};