class Solution {
public:
    int numberOfMatches(int n) {
        if(n<=1)return 0;
        int ans=0;
        if(n%2==0){
            ans+=(n/2+numberOfMatches(n/2));
        }else{
            int x=(n-1)/2;
            int y=x+1;
            ans+=(x+numberOfMatches(y));
        }
        return ans;
    }
};