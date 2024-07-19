class Solution {
public:
    bool p(int x,int y,vector<vector<char>>& board,char val){
        for(int i=0;i<board[0].size();i++){
            cout<<board[i][y]<<" "<<board[x][i];
            if(board[i][y]==val)return true;
            if(board[x][i]==val)return true;
            if(board[3*(x/3)+i/3][3*(y/3)+i%3]==val)return true;
        }
        return false;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board.size(); j++) {
                char val = board[i][j];
                if (val != '.' && val != ' ') {
                    board[i][j] = '.'; // Temporarily mark the cell as empty
                    if (p(i, j, board, val)) return false;
                    board[i][j] = val; // Restore the original value
                }
            }
        }
        return true;
    }
};