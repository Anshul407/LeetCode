class Solution {
public:
    string frequencySort(string s) {
        map<char,int>mp;
        for(auto i:s){
            mp[i]++;
        }
        vector<pair<char,int>>v;
        for(auto i:mp){
            v.push_back({i.second,i.first});
        }
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        string ans="";
        for(auto i:v){
            int freq=i.first;
            while(freq){
                ans+=i.second;
                freq--;
            }
        }
        return ans;
        
    }
};