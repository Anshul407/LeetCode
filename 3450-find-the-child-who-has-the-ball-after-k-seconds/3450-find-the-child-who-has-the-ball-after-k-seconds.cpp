class Solution {
public:
    int solve(int n,int k,int i,int f){
        if(k==0)return i;
        if(!f){
            if(i+1==n-1){
                return solve(n,k-1,i+1,!f);
            }else return solve(n,k-1,i+1,f);
        }else{
            if(i-1==0){
                return solve(n,k-1,i-1,!f);
            }
            else return solve(n,k-1,i-1,f);
        }
        return 0;
    }
    int numberOfChild(int n, int k) {
        return solve(n,k,0,0);
    }
};