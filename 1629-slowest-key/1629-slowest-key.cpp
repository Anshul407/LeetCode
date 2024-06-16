class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        pair<char,int>p;
        int maxi=INT_MIN;
        p.first=keysPressed[0];
        p.second=releaseTimes[0];
        for(int i=1;i<releaseTimes.size();i++){
             int currDuration=releaseTimes[i]-releaseTimes[i-1];
             if(p.second<currDuration){
                p.first=keysPressed[i];
                 p.second=currDuration;
             }
             else if(p.second==currDuration&&p.first<keysPressed[i]){
                p.first=keysPressed[i];
                 p.second=currDuration;
             }
        }
        return p.first;
    }
};