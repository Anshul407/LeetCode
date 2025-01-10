class Solution {
public:
    static bool cmp(pair<char,int>&p,pair<char,int>&q){
        return p.second>q.second;
    }
    string frequencySort(string s) {
        map<char,int>mp;
        for(auto i:s){
            mp[i]++;
        }
        vector<pair<char,int>>v;
        for(auto i:mp){
            v.push_back({i.first,i.second});
        }
        sort(v.begin(),v.end(),cmp);
        string ans="";
        for(auto i:v){
            for(int x=0;x<i.second;x++){
                ans+=i.first;
            }
        }
        return ans;
    }
};