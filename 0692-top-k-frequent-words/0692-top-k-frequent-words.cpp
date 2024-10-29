class Solution {
public:
    map<string,int>mp;
    bool cmp(const string a,const string b){
        if(mp[a]==mp[b]){
            if(a<b)return 1;
            return 0;
        }
        return mp[a]>mp[b];
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        for(auto i:words){
            mp[i]++;
        }
        vector<string>x;
        for(auto i:mp){
            x.push_back(i.first);
        }
        sort(x.begin(),x.end(),[this](const string&a, const string&b){ return cmp(a,b);});
        vector<string>ans;
        for(int i=0;i<min((int)words.size(),k);i++){
            ans.push_back(x[i]);
        }
        return ans;
    }
};