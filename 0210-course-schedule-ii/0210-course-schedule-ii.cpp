class Solution {
public:
    bool dfs(int i,int p,vector<int>&vis,unordered_map<int,vector<int>>mp,vector<int>&ans){
        vis[i]=1;
        for(auto v:mp[i]){
            if(vis[v]==0){
                if(dfs(v,i,vis,mp,ans))return 1;
            }
            else if(i==p)return 1;
        }
        ans.push_back(i);
        return 0;
    }
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<int>ans;
        vector<int>ind(n,0);
       unordered_map<int,vector<int>>mp;
       for(auto i:prerequisites){
            mp[i[1]].push_back(i[0]);
       }
       for(int i=0;i<n;i++){
            if(ind[i]==0)
           if (dfs(i,-1,ind,mp,ans))return{};
       }
       if(ans.size()!=n)return {};
       reverse(ans.begin(),ans.end());
       return ans;
    }
};