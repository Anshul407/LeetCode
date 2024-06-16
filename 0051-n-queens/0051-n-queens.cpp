class Solution {
public:
    bool isSafe(vector<string>&board,int row,int col,int n){
        int i=row,j=col;
        while(i<n&&j>=0){
            if(board[i][j]=='Q'){
                return false;
            }
            i++;j--;
        }
        i=row,j=col;
        while(i>=0&&j>=0){
            if(board[i][j]=='Q'){
                return false;
            }
            i--;j--;
        }
        i=row,j=col;
        while(j>=0){
            if(board[i][j]=='Q'){
                return false;
            }
            j--;

        }
        return 1;
    }
    void solve(vector<string>&board,int n,int col,vector<vector<string>> &ans){
        if(col==n){
            ans.push_back(board);
            return ;
        }
        for(int row=0;row<n;row++){
            if(isSafe(board,row,col,n)){
                board[row][col]='Q';
                solve(board,n,col+1,ans);
                board[row][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        vector<vector<string>> ans;
        solve(board,n,0,ans);
        return ans;
    }
};