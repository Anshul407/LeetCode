class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& eq, vector<double>& values, vector<vector<string>>& queries) {
        map<string,vector<pair<string,double>>>mp;
        int j=0;
        for(auto i:eq){
            mp[i[0]].push_back({i[1],values[j]});
            mp[i[1]].push_back({i[0],1.0/values[j]});
            j++;
        }
        vector<double>ans;
        for(auto i:queries){
            auto s=i[0];
            auto e=i[1];
            if (mp.find(s) == mp.end() || mp.find(e) == mp.end()) {
            ans.push_back(-1.0);
            continue;
            }
            queue<pair<double,string>>q;
            q.push({1.0,s});
            map<string,int>vis;
            vis[s]=1;
            int f=1;
            while(!q.empty()){
                auto node=q.front().second;
                auto wt=q.front().first;
                q.pop();
                if(node==e){
                    ans.push_back(wt);
                    f=0;
                    break;
                }
                for(auto x:mp[node]){
                    if(vis.find(x.first)==vis.end()){
                        q.push({wt*x.second,x.first});
                        vis[x.first]=1;
                    }
                }
            }
            if(f){
                ans.push_back(-1.0);
            }

        }
        return ans;
    }
};