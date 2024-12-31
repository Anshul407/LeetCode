class Solution {
public:
    vector<int>dp;
    int solve(vector<int>&d,int i,vector<int>&c){
        if(i>=d.size())return 0;
        if(dp[i]!=-1)return dp[i];
        int op1=0,op2=0,op3=0;
        int k=i;
        while(k<d.size()&&d[k]<d[i]+1)k++;
        op1=c[0]+solve(d,k,c);
        k=i;
        while(k<d.size()&&d[k]<d[i]+7)k++;
        op2=c[1]+solve(d,k,c);
        k=i;
        while(k<d.size()&&d[k]<d[i]+30)k++;
        op3=c[2]+solve(d,k,c);

        return dp[i]=  min({op1,op2,op3});


    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        dp.resize(days.size()+1,-1);
        return solve(days,0,costs);
    }
};