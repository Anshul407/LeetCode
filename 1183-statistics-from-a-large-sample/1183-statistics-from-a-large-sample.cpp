class Solution {
public:
    long long tot;
    double m(map<int,int>mp){
        long long x=0;
        long long t=0;
        for(auto i:mp){
            x+=1LL*i.first*i.second;
            t+=i.second;
        }
        tot=t;
        return static_cast<double>(x)/t;
    }
    double med(map<int, int> mp) {
        int k=tot/2;
        auto ev=(tot%2==0);
        int c=0,prev=-1;
        for(auto i:mp){
            c+=i.second;
            if(c>k){
                if(ev&&prev!=-1)return (prev+i.first)/2.0;
                return i.first/1.0;
            }
            if(c==k&&ev)prev=i.first;
            
        }
        return 1.0;
    }
    double mod(map<int,int>mp){
        int cur=0;
        int ans=0;
        for(auto i:mp){
            if(i.second>cur){
                cur=i.second;
                ans=i.first;
            }
        }
        return ans/1.0;
    }

    vector<double> sampleStats(vector<int>& count) {
        map<int,int>mp;
        double maxi=0,mini=255.0;
        for(int i=0;i<count.size();i++){
            if(count[i]!=0){mp[i]=count[i];
            mini=min(mini,(double)i);
            maxi=max(maxi,(double)i);
            }
        }
        double mean=m(mp);
        double median=med(mp);
        double mode=mod(mp);
        return {mini,maxi,mean,median,mode};

    }
};