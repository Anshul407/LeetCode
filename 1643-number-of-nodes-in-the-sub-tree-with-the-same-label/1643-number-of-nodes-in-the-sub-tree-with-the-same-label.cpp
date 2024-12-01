class Solution {
public:
    map<int,vector<int>>mp;
    void dfs(int i,int p,string &labels,vector<int>&ans,map<char,int>&mp2){
        int x=mp2[labels[i]];
        for(auto v:mp[i]){
            if(v!=p){
                dfs(v,i,labels,ans,mp2);
            }
        }
        mp2[labels[i]]++;
        ans[i]=mp2[labels[i]]-x;   
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        map<char,int>mp2; 
        for(auto i:edges){
            mp[i[0]].push_back(i[1]);
            mp[i[1]].push_back(i[0]);
        }
        vector<int>ans(n,0);
        dfs(0,-1,labels,ans,mp2);
        return ans;
    }
};