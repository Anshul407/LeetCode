class Solution {
public:
    long long calculateScore(string s) {
        map<char,char>mp;
        char a='a',b='z';
        while(a<b){
            mp[a]=b;
            mp[b]=a;
            a++;
            b--;
        }
        map<char,vector<int>>mp2;
        long long ans=0;
        for(int i=0;i<s.size();i++){
            auto cur=s[i];
            auto search=mp[cur];
            if(mp2.find(search)!=mp2.end()){
                ans=ans+(i-mp2[search].back());
                mp2[search].pop_back();
                if(mp2[search].size()==0)mp2.erase(search);
            }else {
                mp2[cur].push_back(i);
            }
        }
        return ans;
    }
};