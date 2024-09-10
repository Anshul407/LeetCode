class Solution {
public:
    int countPrimes(int n) {
        int cnt=0;
        vector<bool>ans(n+1,1);
        int anss=0;
        ans[1]=0,ans[0]=0;
        for(int i=2;i<n;i++){
           
            if(ans[i]){
                anss++;
            for(int j=i*i;j<n;j+=i){
                ans[j]=0;
            }
            }
        }
        
        
        return anss;
    }
};