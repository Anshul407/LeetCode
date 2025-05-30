class Solution {
public:
    vector<int>vis;
    void solve(int cur,unordered_map<int,vector<int>>&mp,vector<int>&a){
       
        for(auto v:mp[cur]){
            if(a[v]==-1){
                a[v]=a[cur]+1;
                solve(v,mp,a);
            }
        }
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        unordered_map<int,vector<int>>adj;
        for(int i=0;i<edges.size();i++){
            if(edges[i]!=-1)
            adj[i].push_back(edges[i]);
        }
        vis.resize(edges.size()+1,0);
        
        vector<int>a(edges.size()+1,-1);
        a[node1]=0;
        vector<int>b(edges.size()+1,-1);
        b[node2]=0;
         int ans=1e6;
        solve(node1,adj,a);
        vis.resize(edges.size()+1,0);
        solve(node2,adj,b);
        for(int i=0;i<a.size();i++){
            cout<<a[i]<<" "<<b[i]<<" A ";
            if(a[i]==-1||b[i]==-1)continue;
            
            ans=min(ans,max(a[i],b[i]));
        }
        for(int i=0;i<a.size();i++){
            if(a[i]==-1||b[i]==-1)continue;
            if(ans==max(a[i],b[i])){ans=i;break;}
        }
        if(ans==1e6)ans=-1;
        return ans;
    }
};