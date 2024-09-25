class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        map<string,int>mp,mp2;
        for(auto i:banned)mp2[i]++;
        string cur="";
        for(auto i:paragraph){
            if(isalpha(i))cur+=tolower(i);
            else{
                if(cur.size()&&mp2.find(cur)==mp2.end())mp[cur]++;
                cur="";
            }
        }

        int cnt=0;
        string w="";
        for(auto i:mp){
            if(i.second>cnt){
                cnt=i.second;
                w=i.first;
            }
        }
        
        return w;
    }
};