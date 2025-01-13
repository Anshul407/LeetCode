class Solution {
public:
    int minimumLength(string s) {
        map<char,int>mp;
        for(auto i:s){
            mp[i]++;
        }
        int ans=0;
        for(auto i:mp){
            if(i.second>=3){
                while(i.second>2){
                    i.second-=2;
                }
                ans+=i.second;
            }else {
                ans+=i.second;
            }
        }
        return ans;
    }
};