class Solution {
public:
    int solve(int n,int state,int f){
        if(n==0)return 1;
        int ans=0;
        for(int i=0;i<=9;i++){
            if(state&(1<<i))continue;
            if(i==0&&f==0)continue;

            int newstate=state|(1<<i);
            ans+=solve(n-1,newstate,1);
        }return ans;
    }
    int countNumbersWithUniqueDigits(int n) {
        int ans=0;
        for(int i=1;i<=n;i++){
            ans+=solve(i,0,0);
        }return ans+1;
    }
};