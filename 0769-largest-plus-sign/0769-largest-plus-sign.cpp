class Solution {
public:
    int dp[600][600][5];
    int solve(vector<vector<int>>&m,int i,int j,int x,int y){
        int k=0;
        if(x==1)k=1;
        else if(x==-1)k=2;
        else if(y==-1)k=3;
        else if(y==1)k=4;
        if(dp[i][j][k]!=-1)return dp[i][j][k];
        int ii=i,jj=j;
        i=i+x;
        j=j+y;
        if(i<0||j<0||i>=m.size()||j>=m.size()||m[i][j]==0){
            return 0;
        }
        
        return dp[ii][jj][k]= 1+solve(m,i,j,x,y);
    }
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        memset(dp,-1,sizeof(dp));
        vector<vector<int>>m(n,vector<int>(n,1));
        for(auto i:mines){
            m[i[0]][i[1]]=0;
        }
        int ans=0;
        for(int i=0;i<m.size();i++){
            for(int j=0;j<m[0].size();j++){
                if(m[i][j]==1)
                ans=max(ans,1+min({solve(m,i,j,1,0),solve(m,i,j,-1,0),solve(m,i,j,0,1),solve(m,i,j,0,-1)}));
            }
        }
        return ans;
    }
};