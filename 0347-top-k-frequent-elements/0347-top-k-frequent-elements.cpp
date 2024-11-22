class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>>pq;
        map<int,int>mp;
        for(auto i:nums)mp[i]++;
        for(auto i:mp){
            pq.push({i.second,i.first});
        }
        vector<int>ans;
        while(k--){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};