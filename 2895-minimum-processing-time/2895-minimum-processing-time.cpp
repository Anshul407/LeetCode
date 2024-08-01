class Solution {
public:
    int minProcessingTime(vector<int>& processorTime, vector<int>& tasks) {
        sort(processorTime.begin(),processorTime.end());
        sort(tasks.begin(),tasks.end());
        reverse(tasks.begin(),tasks.end());
        int j=0,i=0;
        int ans=0;
        int cnt=0;
        while(i<processorTime.size()&&j<tasks.size()){
            cnt++;
            if(cnt==4){
                ans=max(ans,(processorTime[i]+tasks[j]));
                j++;
                cnt=0;
            }i++;
        }
        return ans;
    }
};