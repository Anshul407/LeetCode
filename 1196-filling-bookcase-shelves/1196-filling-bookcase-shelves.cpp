class Solution {
public:
    int dp[1001][1001];
    int solve(vector<vector<int>>&b,int i,int w,int h,int f){
        if(i>=b.size())return h;
        if(dp[i][w]!=-1)return dp[i][w];
        int op1=INT_MAX,op2=INT_MAX;
        if(b[i][0]+w<=f){
            op1=solve(b,i+1,b[i][0]+w,max(h,b[i][1]),f);
        }

        op2=h+solve(b,i+1,b[i][0],b[i][1],f);

        return dp[i][w]= min(op1,op2);
    }
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        memset(dp,-1,sizeof(dp));
        return solve(books,0,0,0,shelfWidth);
    }
};