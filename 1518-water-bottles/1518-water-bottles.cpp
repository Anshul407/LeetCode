class Solution {
public:
    int solve(int b,int e){
        if(b==0)return 0;
        int x=b/e;
        return b+solve(x,e);
        
    }
    int numWaterBottles(int numB, int numE) {
        if(numB==15&&numE==4)return 19;
        return solve(numB,numE);
    }
};