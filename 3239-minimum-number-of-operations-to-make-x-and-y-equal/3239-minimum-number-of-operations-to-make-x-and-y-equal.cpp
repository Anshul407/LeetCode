class Solution {
public:
    unordered_map<int,int>mp;
    int solve(int x,int y){
        if(x==y)return 0;
        if(x<y)return (y-x);
        if(mp.find(x)!=mp.end())return mp[x];
        int op1=1e6,op2=1e6;
        int op3=1e6,op6=1e6;
        int op4=1e6,op5=1e6;
        int op7=1e6;
        if(x%11==0){
            op1=1+solve(x/11,y);
        }else{
            int tot=x%11;
            op1=min(op1,1+solve(x/11,y)+tot);
            op1=min(op1,1+solve(x/11+1,y)+(11-tot));
        }
        if(x%5==0){
            op4=1+solve(x/5,y);
        }else{
            int tot=x%5;
            op4=min(op4,1+solve(x/5,y)+tot);
            op4=min(op4,1+solve(x/5+1,y)+(5-tot));
        }
        op7=1+solve(x-1,y);

        return mp[x]= min({op1,op4,op7});
    }
    int minimumOperationsToMakeEqual(int x, int y) {
        mp.clear();
        return solve(x,y);
    }
};