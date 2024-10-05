class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        map<int,int>mp;
        for(auto i:s1)mp[i]++;
        int i=0,j=0;
        while(j<s2.size()){
            if(mp.find(s2[j])!=mp.end())mp[s2[j]]--;

            if(j-i+1==s1.size()){
                int f=1;
                for(auto p:mp){
                    if(p.second>0)f=0;
                }
                if(f)return 1;

                if(mp.find(s2[i])!=mp.end()){
                    mp[s2[i]]++;
                }
                i++;
            }
            j++;
        }
        return 0;
    }
};