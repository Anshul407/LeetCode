class Solution {
public:
    int minJumps(vector<int>& arr) {
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]].push_back(i);
        }
        

        queue<pair<int,int>>q;
        q.push({0,0});
        unordered_set<int>vis;
        vis.insert(0);
        while(!q.empty()){
            auto [node,w]=q.front();
            q.pop();
            if(node==arr.size()-1)return w;
            
            if(vis.find(node-1)==vis.end()&&node-1>=0){
                q.push({node-1,w+1});
                vis.insert(node-1);
            }
            if(vis.find(node+1)==vis.end()&&node+1<arr.size()){
                q.push({node+1,w+1});
                vis.insert(node+1);
            }
            for(auto v:mp[arr[node]]){
                if(vis.find(v)==vis.end()){
                    q.push({v,w+1});
                    vis.insert(v);
                }
            }

            mp[arr[node]].clear();
        }
        return -1;
    }
};