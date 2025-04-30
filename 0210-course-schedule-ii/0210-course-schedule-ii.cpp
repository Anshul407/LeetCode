class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
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
        vector<int>ans;
        while(!q.empty()){
            auto cur=q.front();
            ans.push_back(cur);
            q.pop();
            for(auto v:mp[cur]){
                in[v]--;
                if(in[v]==0){
                    q.push(v);
                }
            }
        }
        reverse(ans.begin(),ans.end());
        if(ans.size()<n)return {};
        return ans;
    }
};