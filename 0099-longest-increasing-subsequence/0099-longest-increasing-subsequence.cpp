class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        set<int>st(nums.begin(),nums.end());
        vector<int>v(st.begin(),st.end());
        int m=v.size();
        vector<vector<int>>t(n+1,vector<int>(m+1,0));
        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                if(nums[i-1]==v[j-1]){
                    t[i][j]=1+t[i-1][j-1];
                }
                else{
                    t[i][j]=max(t[i-1][j],t[i][j-1]);
                }
            }
        }
        return t[n][m];
    }
};