class Solution {
public:
    vector<bool>dp;
    bool solve(int sum,int x,int y,int t){
        if(sum==t)return 1;
        if(sum>x+y||sum<0||dp[sum]==true)return 0;
        dp[sum]=1;
        bool op1=solve(sum+x,x,y,t);
        bool op2=solve(sum+y,x,y,t);
        bool op3=solve(sum-x,x,y,t);
        bool op4=solve(sum-y,x,y,t);

        return op1||op2||op3||op4;

    }
    bool canMeasureWater(int x, int y, int target) {
        if(x+y<target)return 0;
        dp.resize(x+y+1,0);
        return solve(0,x,y,target);
    }
};