class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        vector<vector<int>>dis(moveTime.size(),vector<int>(moveTime[0].size(),INT_MAX));
        pq.push({0,{0,0}});
        dis[0][0]=0;
        while(!pq.empty()){
            auto curd=pq.top().first;
            auto x=pq.top().second;
            auto i=x.first;
            auto j=x.second;
            pq.pop();
            if(i==moveTime.size()-1&&j==moveTime[0].size()-1)return curd;
            if(i-1>=0){
                auto xx=i-1+j;
                auto c=xx%2==0?2:1;
                c+=max(moveTime[i-1][j]-curd,0);
                c+=curd;
                if(dis[i-1][j]>c){
                    dis[i-1][j]=c;
                    pq.push({c,{i-1,j}});
                }
            }
             if(j-1>=0){
                auto xx=i-1+j;
                auto c=xx%2==0?2:1;
                c+=max(moveTime[i][j-1]-curd,0);
                c+=curd;
                if(dis[i][j-1]>c){
                    dis[i][j-1]=c;
                    pq.push({c,{i,j-1}});
                }
            }
             if(i+1<moveTime.size()){
                auto xx=i+1+j;
                auto c=xx%2==0?2:1;
                c+=max(moveTime[i+1][j]-curd,0);
                c+=curd;
                if(dis[i+1][j]>c){
                    dis[i+1][j]=c;
                    pq.push({c,{i+1,j}});
                }
            }
               if(j+1<moveTime[0].size()){
                auto xx=i+1+j;
                auto c=xx%2==0?2:1;
                c+=max(moveTime[i][j+1]-curd,0);
                c+=curd;
                if(dis[i][j+1]>c){
                    dis[i][j+1]=c;
                    pq.push({c,{i,j+1}});
                }
            }
        }return -1;
    }
};