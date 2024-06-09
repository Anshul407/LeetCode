class Solution {
public:
    int minBitFlips(int start, int goal) {
        int x=(start^goal);
        int cnt=0;
        while(x){
            if(x%2==1)cnt++;
            x/=2;
        }
        return cnt;
    }
};