class Solution {
public:
    int reinitializePermutation(int n) {
        vector<int>v;
        vector<int>v2;
        vector<int>prem;
        for(int i=0;i<n;i++){v.push_back(i);
        v2.push_back(0);
        prem.push_back(i);
        }
        int cnt=0;
        while(v!=v2){
             
             for(int i=0;i<n;i++){
                if(i%2==0){
                    v2[i]=prem[i/2];
                }
                else{
                    v2[i]=prem[n / 2 + (i - 1) / 2];
                }
             }
             cnt++;
             prem=v2;


        }
        return cnt;
    }
};