class Solution {
public:
    vector<vector<int>>dp;
    int solve(string &s,string &r,int i,int j){
        if(i>=s.length()&&j>=r.length())return 0;
        if(i>=s.length()){
            int sum=0;
            for(int x=j;x<r.length();x++){
                sum+=r[x];
            }
            return sum;
        }
        if(j>=r.length()){
            int sum=0;
            for(int x=i;x<s.length();x++){
                sum+=s[x];
            }
            return sum;
        }
        if(dp[i][j]!=-1)return dp[i][j];

        int op1=0,op2=0,op3=0,op4=0;
        if(s[i]==r[j]){
            op1=solve(s,r,i+1,j+1);
        }
        else{
            op2=s[i]+solve(s,r,i+1,j);
            op3=r[j]+solve(s,r,i,j+1);
            op4=s[i]+r[j]+solve(s,r,i+1,j+1);
        }
        return dp[i][j]= (s[i] == r[j]) ? op1 : min({op2, op3, op4});
    }
    int minimumDeleteSum(string s1, string s2) {
        dp.resize(s1.length(),vector<int>(s2.length(),-1));
       return solve(s1,s2,0,0);
    }
};