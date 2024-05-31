class Solution {
public:
    int hammingWeight(int n) {
        vector<int>x;
        while(n){
            x.push_back(n%2);
            n/=2;
        }
        int cnt=0;
        for(auto i:x){
           if(i==1){
            cnt++;

           }
        }
        return cnt;
    }
};