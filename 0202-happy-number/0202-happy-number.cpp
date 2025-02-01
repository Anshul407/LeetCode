class Solution {
public:
    int s(int cur){
        int x=0;
        while(cur>0){
            int r=cur%10;
            x+=(r*r);
            cur/=10;
        }return x;
    }
    bool isHappy(int n) {
        long long a=n,b=n;
        while(true){
            b=s(b);
            b=s(b);
            a=s(a);
            if(a==1)return 1;
            if(a==b)return 0;
        }return 0;
    }
};