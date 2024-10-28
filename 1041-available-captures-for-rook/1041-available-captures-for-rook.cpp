class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int x,y;
        int ans=0;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]=='R'){
                    x=i;
                    y=j;
                    break;
                }
            }
        }
        int i=x,j=y;
        while(i>=0&&j>=0){
            if(board[i][j]=='B')break;
            else if(board[i][j]=='p'){
                ans++;
                break;
            }
            i--;
        }
        i=x,j=y;
        while(i<board.size()&&j<board[0].size()){
            if(board[i][j]=='B')break;
            else if(board[i][j]=='p'){
                ans++;
                break;
            }
            i++;
        }
        i=x,j=y;
        while(i>=0&&j>=0){
            if(board[i][j]=='B')break;
            else if(board[i][j]=='p'){
                ans++;
                break;
            }
            j--;
        }
        i=x,j=y;
        while(i<board.size()&&j<board[0].size()){
            if(board[i][j]=='B')break;
            else if(board[i][j]=='p'){
                ans++;
                break;
            }
            j++;
        }

        return ans;

    }
};