class Solution {
public:
    int buttonWithLongestTime(vector<vector<int>>& events) {
        int ans=-1;
        int x=INT_MIN;
        for(int i=1;i<events.size();i++)
        {
            if(x==events[i][1]-events[i-1][1]&&ans>events[i][0]){
                x=events[i][1]-events[i-1][1];
                ans=events[i][0];
            }
           else if(x<events[i][1]-events[i-1][1]){
                x=events[i][1]-events[i-1][1];
                ans=events[i][0];
            }
        }
        if(x==events[0][1]&&ans>events[0][0]){
                return events[0][0];
            }
        else if(x<events[0][1])return events[0][0];
        return ans;
    }
};