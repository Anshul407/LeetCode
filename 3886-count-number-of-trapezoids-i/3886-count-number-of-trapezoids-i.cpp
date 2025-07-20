class Solution {
public:
    const int mod=1e9+7;
    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<int,int>mp;
        for(auto &i:points){
            mp[i[1]]++;
        }
        vector<int>v;
        for(auto &i:mp){
            long long cur=i.second;
            cur=(cur*(cur-1)/2);   
            v.push_back(cur);
        
        }
        int ans=0;
        long long cur=0;
        for(auto &i:v){
            cur+=i;
        }
        for(int i=0;i<v.size();i++){
            cur-=v[i];
            ans=(ans+v[i]*(cur))%mod;
        }
        return ans;
    }
};