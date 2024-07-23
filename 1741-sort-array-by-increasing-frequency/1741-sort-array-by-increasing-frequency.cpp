class Solution {
public:
    static bool cmp(pair<int,int>p,pair<int,int>q){
        if(p.second==q.second)return p.first>q.first;
        return p.second<q.second;
    }
    vector<int> frequencySort(vector<int>& nums) {
        map<int,int>mp;
        for(auto i:nums){
            mp[i]++;
        }
        vector<pair<int,int>>v;
        for(auto i:mp){
            v.push_back({i.first,i.second});
        }
        sort(v.begin(),v.end(),cmp);
        vector<int>ans;
        for(auto i:v){
            while(i.second){
            ans.push_back(i.first);
            i.second--;}
        }

        return ans;

    }
};