class Solution {
public:
    unordered_map<string,double>dp;
    double solve(int i,int j,int n,int k){
        if(i<0||j<0||i>=n||j>=n)return 0;
        if(k==0)return 1;
        string key=to_string(i)+"Anshul"+to_string(j)+"Kunwar"+to_string(k);
        if(dp.find(key)!=dp.end())return dp[key];
        double op1=solve(i+2,j+1,n,k-1);
        double op2=solve(i+2,j-1,n,k-1);
        double op3=solve(i-2,j+1,n,k-1);
        double op4=solve(i-2,j-1,n,k-1);
        double op5=solve(i+1,j+2,n,k-1);
        double op6=solve(i-1,j+2,n,k-1);
        double op7=solve(i+1,j-2,n,k-1);
        double op8=solve(i-1,j-2,n,k-1);
        double s=op1+op2+op3+op4+op5+op6+op7+op8;
        return dp[key]= s/8.0;
    }
    double knightProbability(int n, int k, int row, int column) {
       
        return solve(row,column,n,k);
    }
};