class Solution {
public:
    int clumsy(int n) {
        int ans=n;
        int finans=0;
        int x=0;
        int f=0;
        for(int k=n-1;k>=1;k--){
            if(x==0){
                ans*=k;
            }else if(x==1){
                ans/=k;
            }else if(x==2){
                if(k==1)f=1;
                finans+=ans;
                finans+=k;
            }else {
                ans=k;
                ans*=-1;
            }
            x++;
            if(x>3)x=0;

        }
        if(!f)
        finans+=ans;
        return finans;
    }
};