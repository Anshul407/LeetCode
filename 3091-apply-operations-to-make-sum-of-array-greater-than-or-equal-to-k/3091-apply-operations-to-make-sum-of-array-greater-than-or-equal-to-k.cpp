class Solution {
public:
    int minOperations(int k) {
        int mini=INT_MAX;
        for(int i=1;i<=k;i++){
            int op=k/i;
            if(k%i!=0)op++;
            op+=(i-1);
            mini=min(op,mini);
        }
        return mini-1;
    }
};