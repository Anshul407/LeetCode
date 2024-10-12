class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        priority_queue<int ,vector<int>,greater<int>>pq;
        sort(intervals.begin(),intervals.end());
        int ans=0;
        int i=0;
        while(i<intervals.size()){
            if(pq.empty())pq.push(intervals[i][1]);
            else {
                auto node=pq.top();
                pq.pop();
                if(node<intervals[i][0]){
                    node=intervals[i][1];
                    pq.push(node);
                }else {
                    pq.push(node);
                    pq.push(intervals[i][1]);
                }
            }
            i++;
            
            
        }
        return pq.size();
    }
};