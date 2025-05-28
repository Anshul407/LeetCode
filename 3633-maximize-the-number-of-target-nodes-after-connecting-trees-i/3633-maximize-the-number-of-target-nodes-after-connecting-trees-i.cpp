class Solution {
public:
    vector<vector<int>>dp1;
    vector<vector<int>>dp2;
    int kk;
    unordered_map<int,vector<int>>adj1,adj2;
    void solve(int cur){  
        queue<int>q;
        q.push(cur);
        unordered_set<int>vis;
        vis.insert(cur);
        int i=0;
        
        while(!q.empty()){
            int s=q.size();
            
            for(int i=0;i<s;i++){
                auto cur=q.front();
                q.pop();
                for(auto &v:adj1[cur]){
                    if(vis.find(v)==vis.end()){
                        vis.insert(v);
                        q.push(v);
                    }
                }
            }
            if(i-1<0)dp1[cur][i]=s;
            else
            dp1[cur][i]=dp1[cur][i-1]+s;
            i++;
            if(i>kk)break;
        }
    }
    void solve2(int cur){
        queue<int>q;
        q.push(cur);
        unordered_set<int>vis;
        vis.insert(cur);
        int i=1;
        
        while(!q.empty()){
            int s=q.size();
            for(int i=0;i<s;i++){
                auto cur=q.front();
                q.pop();
                for(auto &v:adj2[cur]){
                    if(vis.find(v)==vis.end()){
                        vis.insert(v);
                        q.push(v);
                    }
                }
            }
            dp2[cur][i]=dp2[cur][i-1]+s;
            i++;
            if(i>kk)break;
        }
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        kk=k;
        for(auto &i:edges1){
            adj1[i[0]].push_back(i[1]);
            adj1[i[1]].push_back(i[0]);
        }
        for(auto &i:edges2){
            adj2[i[0]].push_back(i[1]);
            adj2[i[1]].push_back(i[0]);
        }
        dp1.resize(adj1.size()+1,vector<int>(k+2,0));
        dp2.resize(adj2.size()+1,vector<int>(k+2,0));
        if(k==adj1.size()){
            vector<int>ans;
            if(k>=adj2.size()){
                for(int i=0;i<adj1.size();i++){
                    ans.push_back(adj1.size()+adj2.size());
                }
                return ans;
            }
        }
        for(int i=0;i<adj1.size();i++){
            solve(i);
        }
        for(int i=0;i<adj2.size();i++){
            solve2(i);
        }
        for(int i=0;i<dp1.size();i++){
            int maxi=0;
            for(int j=0;j<=k;j++){
                maxi=max(maxi,dp1[i][j]);
            }
            dp1[i][0]=maxi;
        }
        int maxii=0;
        for(int i=0;i<dp2.size();i++){
            int maxi=0;
            for(int j=0;j<=k;j++){
                maxi=max(maxi,dp2[i][j]);
            }
            dp2[i][0]=maxi;
            maxii=max(maxii,maxi);
        }
       
        vector<int>ans1;
        for(int i=0;i<adj1.size();i++){
            auto cur=dp1[i][0];
            int ans=0;
            ans=max(ans,cur+maxii);
            ans1.push_back(ans);
        }return ans1;
    }
};