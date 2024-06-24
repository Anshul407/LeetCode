class Solution {
public:
    int countTestedDevices(vector<int>& battery) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        int cnt=0;
        for(int i=0;i<battery.size();i++){
           battery[i]= battery[i]-cnt;
            if(battery[i]>0){
                cnt++;
            }
        }
        return cnt;
    }
};