class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int x=arr.size()/4;
        map<int,int>mp;
        for(auto i:arr)mp[i]++;
        for(auto i:mp)if(i.second>x)return i.first;
        return -1;
    }
};