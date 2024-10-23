class Solution {
public:
    void solve(int cur,map<int,vector<pair<int,int>>>&mp,vector<int>&values,int maxi,int tot,int &ans){
        if(maxi>=0&&cur==0){
            ans=max(ans,tot);
        } 
        if(maxi<0)return ;
            
        for(auto v:mp[cur]){
            int k=values[v.first];
            values[v.first]=0;
            solve(v.first,mp,values,maxi-v.second,tot+k,ans);
            values[v.first]=k;

        }  
    }
    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
       
        map<int,vector<pair<int,int>>>mp;
        for(auto i:edges){
            mp[i[0]].push_back({i[1],i[2]});
            mp[i[1]].push_back({i[0],i[2]});
        }
        int ans=values[0];
        solve(0,mp,values,maxTime,0,ans);
        return ans;
    
    }
};