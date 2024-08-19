class Solution {
public:
    int solve(int i,vector<int>&dp,int copy,int n){
        if(i==n)return 0;
        if(i>n)return INT_MAX;
        
        int cp=INT_MAX,tk=INT_MAX;

       if (i + i <= n) { 
            cp = solve(i + i, dp, i, n); 
            if (cp != INT_MAX) cp+=2;
        }
        
        if (i + copy <= n) { 
            tk = solve(i + copy, dp, copy, n);  
            if (tk != INT_MAX) tk++;
        }

        return  min(cp,tk);
    }
    int minSteps(int n) {
        if(n==1)return 0;
      
        vector<int>dp(n+1,-1);
        
        return solve(1,dp,1,n)+1;
        
    }
};