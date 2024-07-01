class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<int>ans;
        vector<int>ind(n,0);
        unordered_map<int,vector<int>>mp;
       for(auto i:prerequisites){
            mp[i[1]].push_back(i[0]);
       }
       for(int i=0;i<n;i++){
        for(auto v:mp[i]){
            ind[v]++;
        }
       }
       queue<int>q;
       for(int i=0;i<n;i++){
        if(ind[i]==0)q.push(i);
       }
       while(!q.empty()){
        int u=q.front();
        ans.push_back(u);
        q.pop();
            for(auto v:mp[u]){
                ind[v]--;
                if(ind[v]==0)q.push(v);
            }
       }
       if(ans.size()!=n)return {};
       return ans;
    }
};