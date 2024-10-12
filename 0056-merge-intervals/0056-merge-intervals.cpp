class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        priority_queue<pair<int,int>>pq;
        sort(intervals.begin(),intervals.end());
        int i=0;
        while(i<intervals.size()){
            if(pq.empty()){
                pq.push({intervals[i][1],intervals[i][0]});

            }else{
                auto node=pq.top();
                pq.pop();
                if(intervals[i][0]<=node.first){
                    node.first=max(node.first,intervals[i][1]);
                    pq.push(node);
                }else{
                    pq.push(node);
                    pq.push({intervals[i][1],intervals[i][0]});
                }
            }
            i++;

        }
        vector<vector<int>>ans;
        while(!pq.empty()){
            auto ii=pq.top();
            pq.pop();
            ans.push_back({ii.second,ii.first});
        }
        return ans;
    }
};