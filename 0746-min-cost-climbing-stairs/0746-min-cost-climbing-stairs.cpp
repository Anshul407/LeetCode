class Solution {
public:
    int solve(vector<int>& cost,int i){
        if(i>=cost.size())return 0;
        int c1=cost[i]+solve(cost,i+1);
        int c2=cost[i]+solve(cost,i+2);
        

        return min(c1,c2);

    }
    int minCostClimbingStairs(vector<int>& cost) {
        int i=0;
        
        int ans=0;
        int x=solve(cost,i);
        int y=solve(cost,1);
        return min(x,y);
    }
};