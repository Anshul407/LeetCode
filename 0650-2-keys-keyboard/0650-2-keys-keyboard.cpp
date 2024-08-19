class Solution {
public:
    int solve(int i,vector<int>&dp,int copy,int n){
        if(i==n)return 0;
        if(i>n)return INT_MAX/2;
        
        int copypaste=2+solve(i*2,dp,i,n);

        int paste=1+solve(i+copy,dp,copy,n);

        return  min(copypaste,paste);
    }
    int minSteps(int n) {
        if(n==1)return 0;
       
        vector<int>dp(n+1,-1);
        
        return 1+solve(1,dp,1,n);
        
    }
};