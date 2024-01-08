class Solution {
public:
    int kthGrammar(int n, int k) {
        if(k==1&&n==1)return 0;

        int length=(pow(2,n-1))/2;
        if(k<=length){
            return kthGrammar(n-1, k);
        }
        else{
             return !kthGrammar(n-1, k-length); 
        }
    }
};