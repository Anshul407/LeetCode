class Solution {
public:
    void dfs(int i,vector<int>&vis,unordered_map<int,vector<int>>&mp,stack<int>&st){
        vis[i]=1;
        for(auto v:mp[i]){
            if(!vis[v])dfs(v,vis,mp,st);
        }
        st.push(i);
    }
    void dfs2(int i,vector<int>&vis,unordered_map<int,vector<int>>&mp,int &cnt)
    {
        vis[i]=1;
        cnt++;
        for(auto v:mp[i]){
            if(!vis[v])dfs2(v,vis,mp,cnt);
        }

    }
    int longestCycle(vector<int>& edges) {
        unordered_map<int,vector<int>>mp,mp2;
        for(int i=0;i<edges.size();i++){
            if(edges[i] != -1) mp[i].push_back(edges[i]);
        }
        for(int i=0;i<edges.size();i++){
            if(edges[i] != -1) mp2[edges[i]].push_back(i);
        }
        vector<int>vis(edges.size(),0);
        stack<int>st;
        for(int i=0;i<edges.size();i++){
            if(!vis[i])dfs(i,vis,mp,st);
        }
        vector<int>vis2(edges.size(),0);
        int ans=-1;
        while(!st.empty()){
            auto node=st.top();
            st.pop();
            
            if(!vis2[node]){
                int cnt=0;
                dfs2(node,vis2,mp2,cnt);
                if(cnt>1)
                ans=max(ans,cnt);
            }
        }
        
        return ans;
    }
};
