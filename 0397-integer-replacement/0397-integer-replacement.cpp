class Solution {
public:
    int solve(int n){
        if(n<1)return INT_MAX;
        if(n==1)return 0;
        int ch1=INT_MAX;
        if(n%2==0){
            ch1=solve(n/2);
        }else ch1=solve(n-1);
        if(ch1!=INT_MAX)ch1++;

        int ch2=INT_MAX;
        if(n%2==1)ch2=solve(n+1);
        if(ch2!=INT_MAX)ch2++;

        return min(ch1,ch2);

    }
    int integerReplacement(int n) {
        return solve(n);
    }
};