class Solution {
public:
    int poorPigs(int buckets, int m,int t) {
        int s=t/m;
        s++;
        int i=0;
        while(pow(s,i)<buckets)i++;
        return i;
    }
};