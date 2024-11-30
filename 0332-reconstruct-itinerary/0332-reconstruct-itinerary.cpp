class Solution {
public:
    void solve(unordered_map<string,vector<string>>&mp,string st,vector<string>&ans){
        while(!mp[st].empty()){
            auto x=mp[st][0];
            mp[st].erase(mp[st].begin());
            solve(mp,x,ans);
        }
        ans.push_back(st);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,vector<string>>mp;
        map<string,int>out,ind;
        for(auto v:tickets){
            mp[v[0]].push_back(v[1]);
            out[v[0]]++;
            ind[v[1]]++;
        }
        for(auto &v:mp){
            sort(v.second.begin(),v.second.end());
        }
        string st="JFK";
        for(auto v:out){
            if(v.second-ind[v.first]==1){
                st=v.first;
                break;
            }
        }
        vector<string>ans;
        solve(mp,st,ans);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};