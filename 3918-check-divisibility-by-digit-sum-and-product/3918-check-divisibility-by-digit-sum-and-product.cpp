class Solution {
public:
    bool checkDivisibility(int n) {
        long long a=0,b=1;
        auto x=to_string(n);
        for(auto &i:x){
            a+=(i-'0');
            b*=(i-'0');
        }
        a+=b;
        return !(n%a);
    }
};