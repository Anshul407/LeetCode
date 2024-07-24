class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        map<int,vector<int>>mp;
        vector<string>v;
        for(auto i:nums){
            v.push_back(to_string(i));
        }

        for(auto i:v){
            int num=0;
            for(auto x:i){
               int nu=x-'0';
               int g=mapping[nu];
               num=num*10+(g);
            }
            mp[num].push_back(stoi(i));
        }
        vector<int>ans;
        for(auto i:mp){
            for(auto j:i.second)ans.push_back(j);
        }
        return ans;
        
    }
};