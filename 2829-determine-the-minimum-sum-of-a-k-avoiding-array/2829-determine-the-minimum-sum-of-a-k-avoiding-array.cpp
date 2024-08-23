class Solution {
public:
    int minimumSum(int n, int k) {
        map<int,int>mp;
        int sum=0;
        int i=0;
        while(n){
            i++;
            if(mp.find(k-i)!=mp.end())continue;
            sum+=i;
            n--;


            mp[i]++;
            
           

        }
        return sum;
    }
};