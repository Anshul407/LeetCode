class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        map<int,int>mp;
        int j=1;
        for(auto i:order){
            mp[i]=j;
            j++;
        }
        for(int i=0;i<words.size()-1;i++){
            auto w1=words[i];
            auto w2=words[i+1];
            int f=0;
            for(int x=0;x<min(w1.size(),w2.size());x++){
                if(mp[w1[x]]<mp[w2[x]]){f=1;break;}
                if(mp[w1[x]]>mp[w2[x]])return 0;
            }
             if(w1.size()>w2.size()&&!f)return 0;
        }

        return 1;
    }
};