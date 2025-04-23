class Solution {
public:
    
    int countLargestGroup(int n) {
        int maxi=0;
        map<int,int>mp;
        for(int i=1;i<=n;i++){
            auto num=i;
            int t=0;
            while(num>0){
                t+=(num%10);
                num/=10;
            }
            mp[t]++;
            maxi=max(maxi,mp[t]);
        }int ans=0;
        cout<<maxi<<"j";
        for(auto i:mp){
            if(i.second==maxi)ans++;
        }
        return ans;
    }
};