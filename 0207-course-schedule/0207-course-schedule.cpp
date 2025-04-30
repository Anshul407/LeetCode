class Solution {
public:
 
    bool canFinish(int n, vector<vector<int>>& pre) {
        map<int,vector<int>>mp;
        vector<int>in(n,0);
        for(auto i:pre){
            mp[i[0]].push_back(i[1]);
            mp[i[1]].push_back(i[0]);
            in[i[1]]++;
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(in[i]==0)q.push(i);
        }
        int ans=0;
        while(!q.empty()){
            ans++;
            auto cur=q.front();
            q.pop();
            for(auto v:mp[cur]){
                in[v]--;
                if(in[v]==0){
                    q.push(v);
                }
            }
        }return ans==n;
    }
};