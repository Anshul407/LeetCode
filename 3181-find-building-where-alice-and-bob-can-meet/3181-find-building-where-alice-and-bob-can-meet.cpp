class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        vector<vector<vector<int>>>v(heights.size());
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        vector<int>ans(queries.size(),-1);
        for(int i=0;i<queries.size();i++){
            int a=queries[i][0];
            int b=queries[i][1];
            int maxi=max(a,b);
            int mini=min(a,b);
            if(a==b||heights[maxi]>heights[mini])ans[i]=maxi;
            else {
                v[maxi].push_back({max(heights[maxi],heights[mini]),i});
            }
        }
        for(int i=0;i<heights.size();i++){
            while(!pq.empty()&&pq.top()[0]<heights[i]){
                ans[pq.top()[1]]=i;
                pq.pop();

            }
            for(auto x:v[i]){
                pq.push(x);
            }
        }
        return ans;
    }

};