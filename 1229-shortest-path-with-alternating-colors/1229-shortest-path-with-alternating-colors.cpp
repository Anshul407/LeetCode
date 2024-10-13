class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        map<int,vector<int>>mp1,mp2;
        for(auto i:redEdges)mp1[i[0]].push_back(i[1]);
        for(auto i:blueEdges)mp2[i[0]].push_back(i[1]);
        queue<pair<int,pair<int,int>>>q;
        vector<int>visred(n,INT_MAX);
        vector<int>visblue(n,INT_MAX);
        visred[0]=0;
        visblue[0]=0;
        q.push({0,{0,0}});
        q.push({1,{0,0}});
        int p=0;
        while(!q.empty()){
            auto x=q.front();
            q.pop();
            auto col=x.first;
            auto dist=x.second.first;
            auto node=x.second.second;

            if(col){
                for(auto i:mp1[node]){
                    if(visred[i]==INT_MAX){
                    q.push({0,{dist+1,i}});
                    visred[i]=dist+1;
                }}
            }else{
                for(auto i:mp2[node]){
                    if(visblue[i]==INT_MAX){
                    q.push({1,{dist+1,i}});
                    visblue[i]=dist+1;}
                }
            }
        }
        vector<int>ans(n,0);
        for(int i=0;i<n;i++){
            ans[i]=min(visred[i],visblue[i]);
            if(ans[i]==INT_MAX)ans[i]=-1;
        }
        return ans;

    }
};