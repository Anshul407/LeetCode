class Solution {
public:
    bool solve(vector<vector<char>>& board,int i,int j, string &word,int k,string &cur){
        if(cur==word)return 1;
        if(i<0||j<0||i>=board.size()||j>=board[0].size()||k>=word.size()||board[i][j]=='#'||board[i][j]!=word[k])return 0;
        char c=board[i][j];
        board[i][j]='#';
        cur+=c;
        bool op1=solve(board,i-1,j,word,k+1,cur);
        if(op1==1)return 1;
   
        bool op2=solve(board,i+1,j,word,k+1,cur);
        if(op2==1)return 1;
   
        bool op3=solve(board,i,j-1,word,k+1,cur);
        if(op3==1)return 1;
     
        bool op4=solve(board,i,j+1,word,k+1,cur);
        if(op4==1)return 1;
        cur.pop_back();
        board[i][j]=c;
        return 0;

        
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(word[0]==board[i][j]){
                    string c="";
                    if(solve(board,i,j,word,0,c))return 1;
                }
            }
        }
        return 0;
    }
};