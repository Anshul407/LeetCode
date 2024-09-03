class Solution {
public:
    int solve(vector<int>&a,vector<int>&b,int i,int j){
        if(i>=a.size()||j>=b.size())return 0;
        int tk=0;
        if(a[i]==b[j]){
            tk=1+solve(a,b,i+1,j+1);
        }
        int ntk1,ntk2;
        ntk1=solve(a,b,i,j+1);
        ntk2=solve(a,b,i+1,j);
        return max({tk,ntk1,ntk2});
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        return solve(nums1,nums2,0,0);
    }
};