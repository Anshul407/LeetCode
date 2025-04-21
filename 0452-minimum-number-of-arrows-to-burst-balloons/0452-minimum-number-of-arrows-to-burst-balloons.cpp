class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        vector<vector<int>>p;
        vector<int>prev;
        for(int i=0;i<points.size();i++){
            if(p.empty()){
                p.push_back(points[i]);
                prev=points[i];
            }else{
                auto x=prev;
                auto a=x[0];
                auto b=x[1];
                if(points[i][0]>=a&&points[i][0]<=b){
                    a=min(a,points[i][0]);
                    b=max(b,points[i][1]);
                    prev[0]=max(prev[0],points[i][0]);
                    prev[1]=min(prev[1],points[i][1]);
                    p.pop_back();
                    p.push_back({a,b});
                }else prev=points[i],p.push_back(points[i]);
            }
        }return p.size();
    }
};