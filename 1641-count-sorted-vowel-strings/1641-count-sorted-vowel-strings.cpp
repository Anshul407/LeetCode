class Solution {
public:
    int dp[101][101];
    int solve(vector<char>&v,int n,int i,int j){
        if(j>=v.size()){
            return i==n;
        }
        if(i==n){
            return 1;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        int tk=0;
        tk=solve(v,n,i+1,j);
        int ntk=solve(v,n,i,j+1);

        return dp[i][j]=tk+ntk;
    }
    int countVowelStrings(int n) {
        memset(dp,-1,sizeof(dp));
        vector<char>v={'a','e','i','o','u'};
       return solve(v,n,0,0);
        
    }
};