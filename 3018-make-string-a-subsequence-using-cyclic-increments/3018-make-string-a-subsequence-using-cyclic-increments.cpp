class Solution {
public:
    
    // int solve(string &s,string &t,int i,int j,vector<vector<int>>&dp){
    //     if(i>=s.size())return 0;
    //     if(j>=t.size())return 0;
    //     if(dp[i][j]!=-1)return dp[i][j];
    //     int op1=0;
    //     if(s[i]==t[j]||(t[j]-s[i]==1)||(t[j]=='a'&&s[i]=='z')){
    //         op1=1+solve(s,t,i+1,j+1,dp);
    //     }
    //     int op2=max(solve(s,t,i+1,j,dp),solve(s,t,i,j+1,dp));
    //     return dp[i][j]= max(op1,op2);
    // }
    bool canMakeSubsequence(string s, string t) {
       int i=0,j=0;
       while(i<s.size()&&j<t.size()){
        if(s[i]==t[j]||(t[j]-s[i]==1)||(t[j]=='a'&&s[i]=='z')){
            i++;
            j++;
        }
        else{
            i++;
        }
       }
       return j==t.size();
    }
};