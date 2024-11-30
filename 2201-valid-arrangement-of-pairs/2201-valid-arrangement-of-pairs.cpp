class Solution {
public:
    void solve(unordered_map<int,vector<int>>&mp,int i,vector<int>&ans){
        while(!mp[i].empty()){
            auto x=mp[i].back();
            mp[i].pop_back();
            solve(mp,x,ans);
        }
        ans.push_back(i);
    }
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
       
        unordered_map<int,vector<int>>mp;
        unordered_map<int,int>ind,out;
        for(int i=0;i<pairs.size();i++){
            mp[pairs[i][0]].push_back(pairs[i][1]);
            ind[pairs[i][1]]++;
            out[pairs[i][0]]++;
        }
        int x=pairs[0][0];
        vector<int>ans;
        for(auto i:out){
            if(i.second-ind[i.first]==1){
                x=i.first;
                break;
            }
        }
        solve(mp,x,ans);
        reverse(ans.begin(),ans.end());
        vector<vector<int>>an;
        for(int i=0;i<ans.size()-1;i++){
            an.push_back({ans[i],ans[i+1]});
        }
        return an;
    }
};