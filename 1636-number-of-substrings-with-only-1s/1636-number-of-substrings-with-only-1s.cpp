class Solution {
public:
    const int mod=1e9+7;
    int numSub(string s) {
        int ans=0;
        int i=0;
        int j=0;
        int f=0;
        while(j<s.size()){ 
            f=0;
            if(s[j]=='0'){
                __int128 cur=(j-i);
                cur=((cur*(cur+1))/2)%mod;
                ans+=cur;
                ans%=mod;
                f=1;
                j++;
                i=j;
            }else j++;
            

        }
        if(!f){
            __int128 cur=(j-i);
                cur=((cur*(cur+1))/2)%mod;
                ans+=cur;
                ans%=mod;
        }
        return ans;

    }
};