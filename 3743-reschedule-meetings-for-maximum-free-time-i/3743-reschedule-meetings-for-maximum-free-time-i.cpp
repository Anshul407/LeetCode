class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        vector<int>v;
        v.push_back(startTime[0]-0);
        for(int i=1;i<startTime.size();i++){
            v.push_back(startTime[i]-endTime[i-1]);
        }
        v.push_back(eventTime-endTime.back());
        int i=0,j=0;
        int cur=0;
        int ans=0;
        while(j<v.size()){
            cur+=v[j];
            ans=max(ans,cur);
            if(j-i==k){
                
                cur-=v[i];
                i++;
            }j++;
        }
        return ans;
        
    }
};