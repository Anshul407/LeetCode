class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        map<int,int>mp;
        for(auto i:target){
            mp[i]++;
        }
        for(auto i:arr){
            mp[i]--;
        }
        for(auto i:mp){
            if(i.second!=0)return 0;
        }

        return 1;
    }
};