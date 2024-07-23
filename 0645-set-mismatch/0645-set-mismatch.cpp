class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
      unordered_map<int,int>mp;
        int j=1;
        for(auto i:nums){
            mp[i]++;
            mp[j]++;
            j++;
        }
        int a,b;
        for(auto i:mp){
            if(i.second==1)a=i.first;
            if(i.second>2)b=i.first;
        }
        
        return {b,a};
    }
};