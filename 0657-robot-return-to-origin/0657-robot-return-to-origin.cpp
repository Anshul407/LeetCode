class Solution {
public:
    int solve(string &moves,int i,int a,int b){
        if(i>=moves.size())return a==0&&b==0;

        if(moves[i]=='U'){
            return solve(moves,i+1,a-1,b);
        }else if(moves[i]=='D'){
            return solve(moves,i+1,a+1,b);
        }else if(moves[i]=='R'){
            return solve(moves,i+1,a,b+1);
        }
        return solve(moves,i+1,a,b-1);
        
    }
    bool judgeCircle(string moves) {
        return solve(moves,0,0,0);
    }
};