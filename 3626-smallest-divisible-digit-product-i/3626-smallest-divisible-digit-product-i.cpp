class Solution {
public:
    int smallestNumber(int n, int t) {
        while(true){
            string x=to_string(n);
            int cur=1;
            for(auto i:x){
                cur*=(i-'0');
            }
            if(cur%t==0)return n;
            n++;
        }
        return -1;
    }
};