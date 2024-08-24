class Solution {
public:
    int solve(string s,string t,int i,int j,vector<vector<int>>&dp){
        if(j>=t.length())return 1;
        if(i>=s.length())return 0;


        int tk=0,ntk=0;
        
        if(s[i]==t[j]){
            tk=solve(s,t,i+1,j+1,dp);
        }
        ntk=solve(s,t,i+1,j,dp);

        return tk+ntk;

    }
    int numDistinct(string s, string t) {
        vector<vector<int>>dp(s.length(),vector<int>(t.length(),-1));
        return solve(s,t,0,0,dp);
    }
};