class Solution {
public:
    long long dp[100001][4][3];
    long long solve(string &s,int i,int p,long long cnt){
        if(i>=s.length()){
            return cnt==3;
        }
        if(dp[i][cnt][p+1]!=-1)return dp[i][cnt][p+1];
        long long tk=0;
        if(p==-1||p!=s[i]-'0'&&cnt<=2){
            tk=solve(s,i+1,s[i]-'0',cnt+1);
        }
        long long ntk=solve(s,i+1,p,cnt);

        return dp[i][cnt][p+1]= tk+ntk;
    }
    long long numberOfWays(string s) {
        memset(dp,-1,sizeof(dp));
       return solve(s,0,-1,0);
    }
};