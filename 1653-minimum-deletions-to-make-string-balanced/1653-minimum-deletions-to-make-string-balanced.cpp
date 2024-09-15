class Solution {
public:
    vector<vector<int>>dp;
    int solve(string &s,int i,int x){
        if(i>=s.length())return 0;
        int op1=INT_MAX,op2=INT_MAX;
        if(dp[i][x]!=-1)return dp[i][x];
        if(!x){
            if(s[i]!='a'){
                op1=1+solve(s,i+1,x);
            }
            else{
                op1=solve(s,i+1,x);
            }
            op2=solve(s,i+1,!x);
        }
        else{
            if(s[i]!='b'){
                op1=1+solve(s,i+1,x);
            }else{
                op2=solve(s,i+1,x);
            }
        }

        return dp[i][x]=min(op1,op2);

    }
    int minimumDeletions(string s) {
        if(s.length()==1)return 0;
      dp.resize(s.length(),vector<int>(s.length(),2));
      return solve(s,0,0);

      
    }
};