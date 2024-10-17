class Solution {
public:
    bool isThree(int n) {
        int cnt=0;
        for(int i=1;i<n;i++){
            if(n%i==0)cnt++;
            if(cnt>2)return 0;
        }
        return cnt==2;
        
    }
};