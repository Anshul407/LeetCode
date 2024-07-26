class Solution {
public:
    void solve(vector<vector<int>>&v,int i,int j,int n,int m,int &ans){
        if(i==n-1&&j==m-1){ans++;return ;}
        
        if(i<n-1){
            int up=i+1;
            if(v[up][j]==1){
               v[up][j]=0;
                solve(v,up,j,n,m,ans);
                v[up][j]=1;
            }
        }
        if(j<m-1){
            int up=j+1;
            if(v[i][up]==1){
                v[i][up]=0;
                solve(v,i,up,n,m,ans);
                v[i][up]=1;
            }
        }
    }
    int dpsolve(vector<vector<int>>&v,int i,int j,int n,int m,vector<vector<int>>&dp){
        if(i==n-1&&j==m-1)return 1;
        if(i>=n||j>=m)return 0;
        if(dp[i][j]!=-1)return dp[i][j];

        int forward=0;
        int down=0;
        if(i<n-1){
            int up=i+1;
            if(v[up][j]==1){
               v[up][j]=0;
                forward=dpsolve(v,up,j,n,m,dp);
                v[up][j]=1;
            }
        }
        if(j<m-1){
            int up=j+1;
            if(v[i][up]==1){
                v[i][up]=0;
                down=dpsolve(v,i,up,n,m,dp);
                v[i][up]=1;
            }
        }

        return dp[i][j]=forward+down;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>v(m,vector<int>(n,1));
        vector<vector<int>>dp(m,vector<int>(n,-1));
        int ans=0;
        v[0][0]=0;
        // solve(v,0,0,m,n,ans);
        return dpsolve(v,0,0,m,n,dp);

        // return ans;
    }
};