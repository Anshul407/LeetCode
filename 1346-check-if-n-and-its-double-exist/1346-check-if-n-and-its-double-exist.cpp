class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map<int,int>mp;
        for(auto i:arr)
        {
            if(mp.find(i*2)!=mp.end())return 1;
            mp[i]++;
        }
        return 0;
    }
};