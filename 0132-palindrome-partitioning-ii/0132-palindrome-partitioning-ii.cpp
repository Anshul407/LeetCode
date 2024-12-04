class Solution {
public:
int dp[2001];
    int dp2[2001][2001];
    int pal(string &ss,int i,int j){
        while(i<j){
            if(ss[i]!=ss[j])return dp2[i][j]=0;
            i++;
            j--;
        }
        return dp2[i][j]=1;
    }
    int solve(string &s,int i,int cnt){
        if(i>=s.size())return 0;
        if(dp[i]!=-1)return dp[i];
        int ans=INT_MAX;
        for(int j=i;j<s.size();j++){
            
            int c=0;
            if(dp2[i][j]!=-1)c=dp2[i][j];
            else c=pal(s,i,j);
            if(c){
                int k=solve(s,j+1,cnt+1);
                if(k!=INT_MAX){
                    ans=min(ans,1+k);
                }
            } 
        }
        return dp[i]= ans;
    }
    int minCut(string s) {
        memset(dp,-1,sizeof(dp));
        memset(dp2,-1,sizeof(dp2));
        return solve(s,0,0)==INT_MAX?0:solve(s,0,0)-1;
    }
};