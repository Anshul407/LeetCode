class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        vector<long long> ans;
        
        long long n=num/3;
        if(n==0){
            return {-1,0,1};
        }
        while(n){
            if(n+(n-1)+(n+1)<num)return {};
            if(n+(n-1)+(n+1)==num){
                return {n-1,n,n+1};

               
            }else n--;
        }
        return {};
    }
};