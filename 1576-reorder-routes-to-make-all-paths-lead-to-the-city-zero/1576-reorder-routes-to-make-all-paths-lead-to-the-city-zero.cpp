class Solution {
public:
    map<int,vector<int>>mp,mp2;
    int solve(int i,vector<int>&vis){
        vis[i]=1;
        int ans=0;
        for(auto v:mp[i]){
            if(!vis[v]){
                ans++;
                ans+=solve(v,vis);
            }
        }
        for(auto v:mp2[i]){
            if(!vis[v]){
                ans+=solve(v,vis);
            }
        }
        return ans;
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        
        for(auto i:connections){
            mp[i[0]].push_back(i[1]);
            mp2[i[1]].push_back(i[0]);
        }
        vector<int>vis(n,0);
        return solve(0,vis);
        
    }
};