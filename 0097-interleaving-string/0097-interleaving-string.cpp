class Solution {
public:
    int dp[101][101][201];
    int solve(string &s,string &p,string &t,int i,int j,int k){
        if(k>=t.size())return i==s.size()&&j==p.size();
        if(dp[i][j][k]!=-1)return dp[i][j][k];
        int op1=0,op2=0;
        if(i<s.size()&&s[i]==t[k]){
            op1=solve(s,p,t,i+1,j,k+1);
            
        }
        if(j<p.size()&&p[j]==t[k]){
            op2=solve(s,p,t,i,j+1,k+1);
            
        }
        return dp[i][j][k]=op1||op2;

    }
    bool isInterleave(string s1, string s2, string s3) {
        memset(dp,-1,sizeof(dp));
        if(s1.size()==0)return s2==s3;
        if(s2.size()==0)return s1==s3;
        return solve(s1,s2,s3,0,0,0);
    }
};