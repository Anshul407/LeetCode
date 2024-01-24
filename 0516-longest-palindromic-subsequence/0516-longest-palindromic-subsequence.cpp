class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n=s.length();
        vector<vector<int>>t(n+1,vector<int>(n+1,0));
        string x(s);
        reverse(x.begin(),x.end());
        for(int i=1;i<n+1;i++){
            for(int j=1;j<n+1;j++){
                if(s[i-1]==x[j-1]){
                    t[i][j]=1+t[i-1][j-1];
                }
                else{
                    t[i][j]=max(t[i-1][j],t[i][j-1]);
                }
            }
        }
        return t[n][n];
    }
};