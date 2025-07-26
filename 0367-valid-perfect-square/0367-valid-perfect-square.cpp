class Solution {
public:
    bool isPerfectSquare(int num) {
        long long i=0,j=num;
        while(i<=j){
            auto mid=(i+j)/2;
            if(mid*mid==num){
                return 1;
            }else if(mid*mid<num)i=mid+1;
            else j=mid-1;
        }return 0;
    }
};