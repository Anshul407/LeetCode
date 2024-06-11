class Solution {
public:
    int solve(int d,int n){
        bool sign=true;
        if(d<0&&n>0)sign=false;
        if(d>0&&n<0)sign=false;

        long long den=labs(d),num=labs(n);
        long long ans=0;
        while(den>=num){
            int cnt=0;
            while(den>=(num<<(cnt+1))){
                cnt++;
            }
            den=den-(num<<cnt);
            ans+=(1<<cnt);

            if(ans>=INT_MAX&&sign){
                return INT_MAX;
            }
            if(ans>=INT_MAX&&!sign){
                return INT_MIN;
            }
        }

        if(!sign)return -ans;
        return ans;
    
    }
    int divide(int d, int n) {
        if(d<=INT_MIN&&n==-1)return INT_MAX;
        if(d>=INT_MAX&&n==1)return INT_MAX;
        if((d>=INT_MAX&&n==-1)||(d<=INT_MIN&&n==1))return INT_MIN+1;
        return solve(d,n);
    }
};