class Solution {
public:
   
    bool isSubsequence(string s, string t) {
        int n=s.length();
        int m=t.length();
        vector<vector<int>>tt(n+1,vector<int>(m+1,0));
        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                if(s[i-1]==t[j-1]){
                    tt[i][j]=1+tt[i-1][j-1];
                }
                else tt[i][j]=max(tt[i-1][j],tt[i][j-1]);
            }
        }
        return tt[n][m]==n;
    }
};