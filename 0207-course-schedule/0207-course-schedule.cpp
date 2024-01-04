class Solution {
public:
    bool canFinish(int num, vector<vector<int>>& courses) {

         int n=num;
        vector<int> adj[n];
        vector<int> indegree(n,0);
            for(auto x:courses){
            adj[x[0]].push_back(x[1]);
            indegree[x[1]]++;
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0)q.push(i);
        }
        int cnt=0;
        while(!q.empty()){
int node=q.front();
q.pop();
cnt++;
            for(auto i:adj[node]){
                indegree[i]--;
                if(indegree[i]==0)q.push(i);
            }
        }
    return cnt==n;
        
    }
};