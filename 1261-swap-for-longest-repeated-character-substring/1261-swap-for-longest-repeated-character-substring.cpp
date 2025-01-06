class Solution {
public:
    map<char,int>mp2;
    bool check(map<char,int>&mp){
        if(mp.size()==1)return 1;
        if(mp.size()>2)return 0;
        char f='%';
        char g='%';
        for(auto i:mp){
            if(f=='%')f=i.first;
            else g=i.first;
            
        }
        cout<<f<<" ";
        auto freq=mp2[f];
        auto freq2=mp2[g];
        
        auto curfreq=mp[f];
        auto curfreq2=mp[g];
        int mini=min(curfreq,curfreq2);
        if(mini>1)return 0;

        if(curfreq2==curfreq){
            if(freq>curfreq||freq2>curfreq2)return 1;
            return 0;
        }
        if(curfreq>curfreq2)return freq>curfreq;
        return freq2>curfreq2;
    }
    int maxRepOpt1(string text) {
        for(auto i:text){
            mp2[i]++;
        }
        int i=0,j=0;
        int ans=0;
        map<char,int>mp;
        while(j<text.size()){
            mp[text[j]]++;
            while(check(mp)==false){
            
                mp[text[i]]--;
                if(mp[text[i]]==0)mp.erase(text[i]);
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};