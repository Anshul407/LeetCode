class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        pq.push({0,0,0});
        vector<vector<int>>res(heights.size(),vector<int>(heights[0].size(),INT_MAX));
        res[0][0]=0;
        while(!pq.empty()){
            auto cur=pq.top();
            pq.pop();
            auto d=cur[0];
            auto i=cur[1];
            auto j=cur[2];
            
            if(i-1>=0){
                auto diff=max(d,abs(heights[i][j]-heights[i-1][j]));
                if(res[i-1][j]>diff){
                    res[i-1][j]=diff;
                    pq.push({diff,i-1,j});
                }
            }
            if(i+1<heights.size()){
                auto diff=max(d,abs(heights[i][j]-heights[i+1][j]));
                if(res[i+1][j]>diff){
                    res[i+1][j]=diff;
                    pq.push({diff,i+1,j});
                }
            }
            if(j-1>=0){
                auto diff=max(d,abs(heights[i][j]-heights[i][j-1]));
                if(res[i][j-1]>diff){
                    res[i][j-1]=diff;
                    pq.push({diff,i,j-1});
                }
            }
            if(j+1<heights[0].size()){
                auto diff=max(d,abs(heights[i][j]-heights[i][j+1]));
                if(res[i][j+1]>diff){
                    res[i][j+1]=diff;
                    pq.push({diff,i,j+1});
                }
            }
        }
        return res[res.size()-1][res[0].size()-1];

    }
};