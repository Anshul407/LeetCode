class Solution {
public:
    int kthFactor(int n, int k) {
        int p=0;
        for(int i=1;i<=n;i++){
           if(n%i==0)p++;
           if(k==p)return i;
        }
        return -1;
    }
};