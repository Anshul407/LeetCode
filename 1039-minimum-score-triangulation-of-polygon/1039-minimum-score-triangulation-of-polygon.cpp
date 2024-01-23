class Solution {
public:
     int solve(vector<int>a,int i,int j,int ans,vector<vector<int>>&t){
         if(i>=j){
             return 0;
         }
         if(t[i][j]!=-1){
             return t[i][j];
         }
         for(int k=i;k<j;k++){
             int temp=solve(a,i,k,ans,t)+solve(a,k+1,j,ans,t)+a[i-1]*a[k]*a[j];
             ans=min(ans,temp);
             t[i][j]=ans;
         }
         return ans;
     }
    int minScoreTriangulation(vector<int>& values) {
        vector<vector<int>>t(values.size()+1,vector<int>(values.size()+1,-1));
        int i=1,j=values.size()-1;
        return solve(values,i,j,INT_MAX,t);
    }
};