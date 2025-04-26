class Solution {
public:
    string findCommonResponse(vector<vector<string>>& responses) {
        unordered_map<string,int>mp;
        for(auto i:responses){
            unordered_map<string,int>temp;
            for(auto x:i)temp[x]++;
            for(auto ii:temp){
                mp[ii.first]++;
            }
        }
        int maxi=0;
        for(auto i:mp){
            maxi=max(maxi,i.second);
        }
        string ans="";
        for(auto i:mp){
            if(maxi==i.second){
                if(ans.empty())ans=i.first;
                else ans=min(ans,i.first);
            }
        }return ans;
    }
};