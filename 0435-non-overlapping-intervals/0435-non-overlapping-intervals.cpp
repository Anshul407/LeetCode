class Solution {
public:
   
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) {
        return 0;
    }
    
      sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b) {
            return a[1] < b[1];
        });
        int st_time=intervals[0][0];
        int end_time=intervals[0][1];
        int ans=1;
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]>=end_time){ans++;
                 st_time=intervals[i][0];
                 end_time=intervals[i][1];
            }
        }
        return intervals.size()-ans;
    }
};