class Solution {
public:
    string ss;
    bool solve(vector<vector<char>>& mat,int i,int j,int pos){
        if(mat[i][j]=='#')return 0;
        if(pos==ss.size())
        {
            return true;
        }
        char k=mat[i][j];
        mat[i][j]='#';
        bool up=false,down=false,right=false,left=false;
        if(i-1>=0&&mat[i-1][j]==ss[pos])
        up=solve(mat,i-1,j,pos+1);
        if(i+1<mat.size()&&mat[i+1][j]==ss[pos])
        down=solve(mat,i+1,j,pos+1);
        if(j-1>=0&&mat[i][j-1]==ss[pos])
        left=solve(mat,i,j-1,pos+1);
        if(j+1<mat[0].size()&&mat[i][j+1]==ss[pos])
        right=solve(mat,i,j+1,pos+1);
        mat[i][j]=k;
        return up||down||right||left;
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        ss=word;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(word[0]==board[i][j]&&solve(board,i,j,1))
                return true;
            }
        }
        return false;
    }
};