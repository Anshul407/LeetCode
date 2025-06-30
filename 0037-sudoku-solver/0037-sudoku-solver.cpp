class Solution {
public:
    bool check(vector<vector<char>>&b,int i,int j,char x){
        for(int l=0;l<b.size();l++){
            if(b[i][l]==x)return 0;
            if(b[l][j]==x)return 0;
            if(b[3*(i/3)+l/3][3*(j/3)+l%3]==x)return false;
        }   
        return 1;

    }
    int solve(vector<vector<char>>&b){
       
        
        for(int i=0;i<b.size();i++){
            for(int j=0;j<b.size();j++){
            if(b[i][j]!='.')continue;
            for(char x='1';x<='9';x++){
                if(check(b,i,j,x)){
                    b[i][j]=x;
                    if(solve(b))return 1;
                    b[i][j]='.';
                }
            }
            return 0;
            }
        }
        return 1;
    }
    void solveSudoku(vector<vector<char>>& board) {
        
        solve(board);
    }
};