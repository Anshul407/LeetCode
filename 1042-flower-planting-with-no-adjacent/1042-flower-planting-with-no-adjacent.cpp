class Solution {
public:
    void dfs(int i,vector<int>&ans,map<int,vector<int>>&mp,int c){
        ans[i]=c;
        for(auto v:mp[i]){
            if(!ans[v]){
                dfs(v,ans,mp,c+1);
            }
        }
    }
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        map<int,vector<int>>mp;
        for(auto i:paths){
            mp[i[0]].push_back(i[1]);
            mp[i[1]].push_back(i[0]);
        }
        vector<int>ans(n+1,0);
        for(int i=1;i<=n;i++){
            if(ans[i]==0){
                dfs(i,ans,mp,1);
            }
        }
        ans.erase(ans.begin());
        return ans;
    }
};