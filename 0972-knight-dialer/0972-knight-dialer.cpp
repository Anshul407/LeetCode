class Solution {
public:
    const int mod=1e9+7;
    int dp[4][3][5001];
    int solve(int i,int j,vector<vector<char>>&m,int n){
        if(i<0||j<0||i>=m.size()||j>=m[0].size()||m[i][j]=='#')return 0;
        if(n==1)return 1;
        if(m[i][j]=='#')return 0;
        if(dp[i][j][n]!=-1)return dp[i][j][n];
        int ans=0;
        
        
        ans=(ans+solve(i-1,j-2,m,n-1))%mod;
        ans=(ans+solve(i+1,j-2,m,n-1))%mod;
        ans=(ans+solve(i+2,j-1,m,n-1))%mod;
        ans=(ans+solve(i+2,j+1,m,n-1))%mod;
        ans=(ans+solve(i-1,j+2,m,n-1))%mod;
        ans=(ans+solve(i+1,j+2,m,n-1))%mod;
        ans=(ans+solve(i-2,j-1,m,n-1))%mod;
        ans=(ans+solve(i-2,j+1,m,n-1))%mod;
        

        return dp[i][j][n]=ans%mod;
    }
    int knightDialer(int n) {

        vector<vector<char>>m(4,vector<char>(3,0));
        memset(dp,-1,sizeof(dp));
        int x='1';
        for(int i=0;i<4;i++){
            for(int j=0;j<3;j++){
                m[i][j]=x;
                x++;
            }
        }
        m[3][0]='#';
        m[3][1]='0';
        m[3][2]='#';
        int ans=0;
        for(int i=0;i<4;i++){
            for(int j=0;j<3;j++){
                cout<<m[i][j]<<" ";
                if(m[i][j]!='#')
                ans=(ans+solve(i,j,m,n))%mod;
            }
        }
        return ans;
    }
};